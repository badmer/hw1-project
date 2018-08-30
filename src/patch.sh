#!/bin/sh
cat "service dream ${SYS_ROOT}/dist/service
		class main" >> ${SYS_ROOT}/platform-tool/material/init.rc

cat "on property:vold.decrypt=trigger_restart_min_framework
		class_start main" >> ${SYS_ROOT}/platform-tool/material/init.rc