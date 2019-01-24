#!/usr/bin/env python
import time
import os
import sys
import re
import smtplib
from email.mime.text import MIMEText

sizes = dict()
MAX_EMAIL = 100

mailcnt = 0
last_email_time = 0

def email(subj, message):
    global MAX_EMAIL, mailcnt, last_email_time
    if time.time() - last_email_time > 60 * 5:
        mailcnt = 0
    mailcnt += 1
    if mailcnt > MAX_EMAIL: return
    msg = MIMEText(message)
    msg['Subject'] = subj
    ase = 'ase-exec@tower-research.com'
    user = 'ase-exec@tower-research.com'
    msg['To'] = ase
    msg['From'] = user
    s = smtplib.SMTP()
    s.connect()
    s.sendmail( user, ase, msg.as_string() )
    s.quit()

    last_email_time = time.time()

if __name__ == "__main__":    
    first_loop = True
    start = time.time()
    while 1:
        lines_to_mail = ""
        cmd = "ls " + os.environ["EXEC_LOG_DIR"] + "/*.log"
        filenames = os.popen(cmd).readlines()
        for filename in filenames:
            filename = filename[0:-1]
            if os.path.basename(filename).startswith("."):
                continue
            new_size = os.path.getsize(filename)
            if not sizes.has_key(filename):
                if first_loop:
                    sizes[filename] = new_size
                else:
                    sizes[filename] = 0
            if new_size != sizes[filename]:
                f = file(filename)
                f.seek(sizes[filename])
                found_errors = False
                for line in f:
                    if re.search("CRIT ", line):
                        lines_to_mail += filename+": "+line
                        found_errors = True
                f.close()
                sizes[filename] = new_size
                if found_errors:
                    lines_to_mail += "\n"
        if len(lines_to_mail) > 0: 
            email("Log Checker on " + os.environ["HOSTNAME"], lines_to_mail)
        lines_to_mail= ""
        time.sleep(5 * 60)
        first_loop = False
        if time.time() - start > 60*60*7.5: sys.exit();
