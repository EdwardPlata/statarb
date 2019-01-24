#!/usr/bin/env python
import string
import sys
import time
import os
import logging
import copy
import datetime
import socket
import time
from time import localtime, strftime
import subprocess
import copy
import pwd

from optparse import OptionParser
from email.MIMEMultipart import MIMEMultipart
from email.MIMEBase import MIMEBase
from email.MIMEText import MIMEText
from email import Encoders
import smtplib


_date = strftime("%Y%m%d", localtime())
_monitordir = os.environ['EXEC_LOG_DIR'] + '/monitor'
_options, _args = (None, None)
_option_parser  = OptionParser()

def add_option(*kwds, **kargs):
    _option_parser.add_option(*kwds, **kargs)

def get_option(option):
    if hasattr(_options, option):
        return getattr(_options, option)
    return None

def init():
    global _options, _args
    _options, _args = _option_parser.parse_args()
    
    
def display_addrport(apstr):
  addr, port = apstr.split(':')
  addr = int(addr, 16)
  port = int(port, 16)
  return "%d.%d.%d.%d:%d" % ((addr & 0x000000ff),
                             (addr & 0x0000ff00) >> 8,
                             (addr & 0x00ff0000) >> 16,
                             (addr & 0xff000000) >> 24,
                             port)

def display_uid(uid):
  return pwd.getpwuid(uid).pw_name

def run_command(cmd, silence=True):
    if not silence:
        print cmd
    p = subprocess.Popen(cmd,
                         shell=True,
                         stdout=subprocess.PIPE,
                         stderr=subprocess.PIPE,
                         close_fds=True)
    retcode = p.wait()
    (fin, fout, ferr) = (p.stdin, p.stdout, p.stderr)
    if not silence:
        print "".join(fout.readlines())
        print "".join(ferr.readlines())
    return (retcode, fout, ferr)
    
def notify(tag, sender="", data=[], attach="summary.txt", recipients=[], title="Report"):
    """
    Send out notification messages to parties interested
    Try to save a copy of the log for future investigation
    """

    try:
        n = str(datetime.datetime.now())
        t = strftime("%H%M%S", localtime())
        fname = os.path.join(_monitordir, "hostchecks.log.",t)
        if not os.path.exists(_monitordir):
            os.makedirs(_monitordir)
        fh = open(fname, "w")
        print >> fh, n
        for m in data:
            print >> fh, m
        fh.close()
    except Exception, e:
        pass

    recipients = recipients or []
    if len(recipients) == 0:
        return
    recipients = copy.deepcopy(recipients)
    msg             = MIMEMultipart()
    msg["Subject"]  = "%s: %s %s" %(tag, title, str(datetime.datetime.today().strftime("%H:%M:%S")))
    msg["From"]     = sender
    msg["Reply-To"] = sender
    msg.attach(MIMEText("\r\n".join(data)))
    to = []
    for x in recipients:
        if x.find("@") < 0:
            to.append('%s@%s' %(x, "tower-research.com"))
        else:
            to.append(x)
    msg["To"] = ",".join(to)
    s = smtplib.SMTP("mail.tower-research.com")
    s.sendmail("%s@%s" %(sender, socket.getfqdn()), to, msg.as_string())
    s.quit()


def check_interface(start_interface, end_interface):
  email_data =[]
  
  for interface in end_interface:
    diff = dict(map(lambda x: (x, int(end_interface[interface][x]) - int(start_interface[interface][x])), end_interface[interface].keys()))
    errors = diff["rxdrops"] > 0 or diff["rxerrors"] > 0 or diff["txdrops"] > 0 or diff["txerrors"]
    if errors:
      email_data.append("Issues detected on %s :" %interface)      
      email_data.append("Packets received:  %s" %diff["rxpackets"])
      email_data.append("Packets sent:      %s" %diff["txpackets"])
      email_data.append("Receive errors:    %s" %diff["rxerrors"])
      email_data.append("Receive drops:    %s" %diff["rxdrops"])
      email_data.append("Send errors:    %s" %diff["txerrors"])
      email_data.append("Send drops:    %s" %diff["txdrops"])

  return email_data

def interface(snap,timestamp):
  
  if snap:
    cp_cmd = "cp /proc/net/dev %s/interface/interface.%s" %(_monitordir, timestamp)
    (code,out,err) = run_command(cp_cmd)
    
    if len(err.readlines()) > 0:
      errs = err.readlines()
      errs.insert(0,"Error copying /proc/net/dev to %s/interface/interface.%s" %(_monitordir, timestamp))
      
      notify("ERROR",
	      sender="HostChecks",
	      data=errs,
	      recipients=get_option("recipients").split(","),
	      title="Interface snapshot unsuccessful")         

  fh = open("/proc/net/dev")
  data = {}
  map = {}
  counter = 0
  for l in fh.readlines():
    l = l.replace(":"," ")
    fields = l.split()
    if counter == 1:
      map[2] = "rxpackets"
      map[3] = "rxerrors"
      map[4] = "rxdrops"
      map[10] = "txpackets"
      map[11] = "txerrors"
      map[12] = "txdrops"
    if counter > 1:
      subdata = {}
      for i in range(len(fields)):
        if i in map:
          if map[i] == "interface":
            subdata[map[i]] = fields[i]
          else:
            subdata[map[i]] = int(fields[i])
      data[fields[0]] = subdata
    counter = int(counter) + 1
    
  return data
  # {'lo': {'rxerrors': 0, 'rxpackets': 7661314, 'txpackets': 7661314, 'txerrors': 0, 'rxdrops': 0, 'txdrops': 0}, 'eth1': {'rxerrors': 0, 'rxpackets': 0, 'txpackets': 0, 'txerrors': 0, 'rxdrops': 0, 'txdrops': 0}, 'eth0': {'rxerrors': 1, 'rxpackets': 6220363364, 'txpackets': 5657043682, 'txerrors': 0, 'rxdrops': 44994, 'txdrops': 0}}

def check_ifconfig(start_ifconfig, end_ifconfig):
  email_data =[]
  
  for interface in end_ifconfig:
      
    diff = dict(map(lambda x: (x, int(end_ifconfig[interface][x]) - int(start_ifconfig[interface][x])), end_ifconfig[interface].keys()))
    errors = diff["collisions"] > 0 or diff["rxdropped"] > 0 or diff["rxerrors"] > 0 or diff["txdropped"] > 0 or diff["txerrors"]
    if errors:
      email_data.append("Issues detected on %s :" %interface)      
      email_data.append("Packets received:  %s" %diff["rxpackets"])
      email_data.append("Packets sent:      %s" %diff["txpackets"])
      email_data.append("Receive errors:    %s" %diff["rxerrors"])
      email_data.append("Receive drops:    %s" %diff["rxdropped"])
      email_data.append("Send errors:    %s" %diff["txerrors"])
      email_data.append("Send drops:    %s" %diff["txdropped"])
      
  return email_data


def ifconfig(snap,timestamp):
  
  if snap:
    cp_cmd = "/sbin/ifconfig -a > %s/ifconfig/ifconfig.%s" %(_monitordir, timestamp)
    (code,out,err) = run_command(cp_cmd)
    
    if len(err.readlines()) > 0:
      errs = err.readlines()
      errs.insert(0,"Error saving ifconfig output to %s/ifconfig/ifconfig.%s" %(_monitordir, timestamp))
      
      notify("ERROR",
	      sender="HostChecks",
	      data=errs,
	      recipients=get_option("recipients").split(","),
	      title="ifconfig snapshot unsuccessful") 
	      
  cmd="/sbin/ifconfig -a|grep -B3 -A4 'UP BROADCAST'"
  (code,fout,ferr) = run_command(cmd)
  output = fout.readlines()
  data={}
  counter=0
  subdata={}
  for d in output:
     if "--" in d or not d.strip():
       continue
     if counter == 0:
       interface = d.split()[0]
     if "RX packets" in d:
       items = d.strip().split(" ")
       rxpackets = items[1].split(":")[1]
       errors = items[2].split(":")[1]
       dropped = items[3].split(":")[1]
       overruns = items[4].split(":")[1]
       frame = items[5].split(":")[1]
       subdata["rxpackets"] = rxpackets
       subdata["rxerrors"] = errors
       subdata["rxdropped"] = dropped
       subdata["rxoverruns"] = overruns
       subdata["rxframe"] = frame
     if "TX packets" in d: 
       items = d.strip().split(" ")
       txpackets = items[1].split(":")[1]
       errors = items[2].split(":")[1]
       dropped = items[3].split(":")[1]
       overruns = items[4].split(":")[1]
       frame = items[5].split(":")[1]
       subdata["txpackets"] = txpackets
       subdata["txerrors"] = errors
       subdata["txdropped"] = dropped
       subdata["txoverruns"] = overruns
       subdata["txframe"] = frame
     if "collisions" in d: 
       collisions = d.strip().split(" ")[0].split(":")[1]
       subdata["collisions"] = collisions
     
     if counter < 7:
       counter = int(counter) + 1
     else:
       data[interface] = subdata
       subdata = {}
       counter = 0
     
  return data
  # {'bond0.799': {'collisions': '0', 'rxoverruns': '0', 'rxdropped': '0', 'rxerrors': '0', 'rxpackets': '903766', 'txdropped': '0', 'txpackets': '580813', 'txerrors': '0', 'rxframe': '0', 'txframe': '0', 'txoverruns': '0'}, 'bond0': {'collisions': '0', 'rxoverruns': '0', 'rxdropped': '0', 'rxerrors': '0', 'rxpackets': '42981560', 'txdropped': '0', 'txpackets': '16016975', 'txerrors': '0', 'rxframe': '0', 'txframe': '0', 'txoverruns': '0'}, 'bond0.748': {'collisions': '0', 'rxoverruns': '0', 'rxdropped': '0', 'rxerrors': '0', 'rxpackets': '167576', 'txdropped': '0', 'txpackets': '2486', 'txerrors': '0', 'rxframe': '0', 'txframe': '0', 'txoverruns': '0'}, 'eth0': {'collisions': '0', 'rxoverruns': '0', 'rxdropped': '0', 'rxerrors': '0', 'rxpackets': '28043953', 'txdropped': '0', 'txpackets': '16016717', 'txerrors': '0', 'rxframe': '0', 'txframe': '0', 'txoverruns': '0'}}
  
  
def udp_by_port(snap,timestamp):  
  header = True
  map    = { }
  data   = { }  
  
  if snap:
    cp_cmd = "cp /proc/net/udp %s/udp/udp.%s" %(_monitordir, timestamp)
    (code,out,err) = run_command(cp_cmd)
    
    if len(err.readlines()) > 0:
      errs = err.readlines()
      errs.insert(0,"Error copying /proc/net/udp to %s/udp/udp.%s" %(_monitordir, timestamp))
      
      notify("ERROR",
	      sender="HostChecks",
	      data=errs,
	      recipients=get_option("recipients").split(","),
	      title="UDP snapshot unsuccessful")      
  
  fh = open("/proc/net/udp")
  for line in fh.readlines():
    fields = line.split()
    if header:
      header = False
      map[0]  = "sl"
      map[1]  = "local_address"
      map[2]  = "rem_address"
      map[7]  = "uid"
      map[12] = "drops"
    else:
      subdata = { }
      for i in range(len(fields)):
        if i in map:
          if map[i] == "drops" or map[i] == "uid":
            subdata[map[i]] = int(fields[i])
          else:
            subdata[map[i]] = fields[i]
      data[fields[0]] = subdata
  return data

def udp_summary(snap,timestamp):
  header = True
  map    = { }
  data   = { }
  
  if snap:
    cp_cmd = "cp /proc/net/snmp %s/snmp/snmp.%s" %(_monitordir,timestamp)
    (code,out,err) = run_command(cp_cmd)
    

    if len(err.readlines()) > 0:
      errs = err.readlines()
      errs.insert(0,"Error copying /proc/net/snmp to %s/snmp/snmp.%s" %(_monitordir,timestamp))
      notify("ERROR",
	      sender="HostChecks",
	      data=errs,
	      recipients=get_option("recipients").split(","),
	      title="SNMP snapshot unsuccessful")
	      
  fh = open("/proc/net/snmp")
  for line in fh.readlines():   
    fields = line.split()
    if fields[0] == "Udp:":
      if header:
        header = False
        for i in range(1, len(fields)):
          map[i] = fields[i]
      else:
        for i in range(1, len(fields)):
          data[map[i]] = int(fields[i])
  
  return data


def check_udperrors(start_udpsum, end_udpsum, start_udpport, end_udpport, frequency):

  diff = dict(map(lambda x: (x, int(end_udpsum[x]) - int(start_udpsum[x])), end_udpsum.keys()))
  rate = dict(map(lambda (x, y): (x, y / int(frequency)), diff.items()))
  email_data =[]
  
  error = diff["RcvbufErrors"] > 0 or diff["SndbufErrors"] > 0

  
  if error:
      email_data.append( "UDP packets received: %d total, %d/second" % (diff["InDatagrams"],  rate["InDatagrams"] ))
      email_data.append( "UDP packets sent:     %d total, %d/second" % (diff["OutDatagrams"], rate["OutDatagrams"]))
      email_data.append( "UDP receive errors:   %d total, %d/second" % (diff["RcvbufErrors"], rate["RcvbufErrors"]))
      email_data.append( "UDP send errors:      %d total, %d/second" % (diff["SndbufErrors"], rate["SndbufErrors"]))

      if error:
        diff = end_udpport
        for sl in end_udpport:
          if sl in start_udpport:
            diff[sl]["drops"] -= start_udpport[sl]["drops"]
        result = dict(filter(lambda (x, y): y["drops"] > 0, diff.items()))

        if len(result) > 0:
          email_data.append( "Affected sockets are:")
          for sl in result:
            email_data.append( "%s => %s (%s): %d total" % (display_addrport(diff[sl]["local_address"]),
                                               display_addrport(diff[sl]["rem_address"]),
                                               display_uid(diff[sl]["uid"]),
                                               diff[sl]["drops"]))

  return email_data

def check_loop(frequency,snapshot):
  
  last_snap = 0
  host = socket.gethostname()
  exit_time = datetime.datetime.now().replace(hour=16,minute=1,second=0)
  
  while True:
    
    emaildata=[]
    snap = True
    currtime = int(time.time()) 
    next_snap = last_snap + int(snapshot) 
    hour = int(strftime("%H", localtime()))

    
    #if last_snap == 0 or currtime >= next_snap: #and currtime < (next_snap + int(frequency))):
    #  last_snap = int(time.time())    
    #  snap = True

   
   
    timestamp = strftime("%H%M%S", localtime())
    start_udpsum = udp_summary(snap,timestamp)
    start_udpport = udp_by_port(snap,timestamp)
    start_ifconfig = ifconfig(snap,timestamp)
    start_interface = interface(snap,timestamp)
    
    time.sleep(float(frequency))
    
    snap = False
    end_udpsum = udp_summary(snap,timestamp)
    end_udpport = udp_by_port(snap,timestamp)
    end_ifconfig = ifconfig(snap,timestamp)
    end_interface = interface(snap,timestamp)
    
    udperrors_out = check_udperrors(start_udpsum, end_udpsum, start_udpport, end_udpport,frequency)
    ifconfig_out = check_ifconfig(start_ifconfig, end_ifconfig)
    interface_out = check_interface(start_interface, end_interface)
    
    if len(udperrors_out) > 0:
      emaildata.append("\n======== UDP Errors Detected ==========")
      emaildata.extend(udperrors_out)
    if len(ifconfig_out) > 0:
      emaildata.append("\n======== IFCONFIG Errors Detected ==========")
      emaildata.extend(ifconfig_out)
    if len(interface_out) > 0:
      emaildata.append("\n======== ETHERNET INTERFACE Errors Detected =========")
      emaildata.extend(interface_out)
    
    if len(emaildata) > 0:
      notify("ALERT",
	      sender="HostChecks",
	      data=emaildata,
	      recipients=get_option("recipients").split(","),
	      title="HOST NETWORK INTERFACE ISSUES - %s" %host)      

    if hour == 00:
      break
    
    if datetime.datetime.now() > exit_time:
      break

      
def main():
    add_option("--snapshot",default="3600",help="snapshot frequency in seconds")
    add_option("--frequency",default="60",help="delta check frequency in seconds")
    add_option("--recipients",default="infra-support",help="alert email recipients")
    
    init()
    
    frequency = get_option("frequency")
    snapshot = get_option("snapshot")
    recipients = get_option("recipients").split(",")
    
    if not os.path.exists(_monitordir):
      os.makedirs(_monitordir+"/snmp")
      os.makedirs(_monitordir+"/interface")
      os.makedirs(_monitordir+"/udp")
      os.makedirs(_monitordir+"/ifconfig")
      
      
    check_loop(frequency,snapshot)


if __name__ == "__main__":
    sys.exit(main())
