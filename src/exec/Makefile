include $(SRC_DIR)/Makefile.inc

server:
	cd $(INSTALL_DIR)/infra/dev; bjam -j3 link=static release $(SRC_DIR)/exec/cpp/guillotine-server//gt-server 
install:
	#bin
	mkdir -p $(EXEC_ROOT_DIR)/log
	mkdir -p $(EXEC_ROOT_DIR)/bin
	rsync -va $(SRC_DIR)/exec/bin/* $(EXEC_ROOT_DIR)/bin/
	rsync -va $(SRC_DIR)/exec/python/bin/* $(EXEC_ROOT_DIR)/bin/
	#gt-server-conf
	rsync -va $(SRC_DIR)/config/exec/rts1.conf $(EXEC_ROOT_DIR)/gt-server-conf/
	rsync -va $(SRC_DIR)/config/exec/processmanager.conf $(EXEC_ROOT_DIR)/gt-server-conf/
	for number in 1  3 4 5 6 7; do \
		rsync -rva $(SRC_DIR)/config/exec/exectrade$$number.jc $(EXEC_ROOT_DIR)/gt-server-conf ; \
	done
	#gt-params
	rsync -va --exclude='exectrade*' --exclude='rts1.conf' --exclude='processmanager.conf' $(SRC_DIR)/config/exec/* $(EXEC_ROOT_DIR)/gt-params
clean:
	$(RM) $(OBJ_DIR)/cpp/build
context:
	#bin
	mkdir -p $(EXEC_ROOT_DIR)/log
	mkdir -p $(EXEC_ROOT_DIR)/bin
	rsync -va `find $(OBJ_DIR)/cpp/build/bin.opteron_rhel4/guillotine-server/intel-linux-12.0/release/debug-symbols-on/link-static/threading-multi -name gt-server` $(EXEC_ROOT_DIR)/bin/gt-server.$(DATE)
	rsync -va $(SRC_DIR)/exec/bin/* $(EXEC_ROOT_DIR)/bin/
	rsync -va $(SRC_DIR)/exec/python/bin/* $(EXEC_ROOT_DIR)/bin/
	rm -f $(EXEC_ROOT_DIR)/bin/gt-server.rts1
	ln -s $(EXEC_ROOT_DIR)/bin/gt-server.$(DATE) $(EXEC_ROOT_DIR)/bin/gt-server.rts1
	#gt-server-conf
	rsync -va $(SRC_DIR)/config/exec/rts1.conf $(EXEC_ROOT_DIR)/gt-server-conf/
	rsync -va $(SRC_DIR)/config/exec/processmanager.conf $(EXEC_ROOT_DIR)/gt-server-conf/
	for number in 1  3 4 5 6 7; do \
		rsync -rva $(SRC_DIR)/config/exec/exectrade$$number.jc $(EXEC_ROOT_DIR)/gt-server-conf ; \
	done
	#gt-params
	rsync -va --exclude='exectrade*' --exclude='rts1.conf' --exclude='processmanager.conf' $(SRC_DIR)/config/exec/* $(EXEC_ROOT_DIR)/gt-params
