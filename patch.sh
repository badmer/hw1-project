#!/bin/sh
echo "service c_service $SYS_ROOT/platform-tool/aosp/bin/c_service
	class main
	user root
	group root system
	oneshot" >> ${SYS_ROOT}/platform-tool/$AOSP_V/init.rc

echo "on property:vold.decrypt=trigger_restart_min_framework
	class main" >> ${SYS_ROOT}/platform-tool/$AOSP_V/init.rc
		