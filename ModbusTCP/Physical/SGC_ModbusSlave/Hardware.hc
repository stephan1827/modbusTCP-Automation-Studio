 
[hardwarekonfig]
wurzel: 4
[2.1]
[2.100]
moduladr: 0
version: 1.0.1.0
steckplatzgrp: "cpubus"
steckplatzinfo: NUMMER=1, MODULID=1, FLAGS=1
steckplatzgrp: "x20ntbus"
steckplatzinfo: NUMMER=1, MODULID=3, FLAGS=1
anschlussgrp: "ser1"
anschlussinfo: NUMMER=1, MODULID=0, FLAGS=0
[2.101]
{2.109}
klasse: "X20BB22"
comparam_ser1: 57600,e,8,1, TYPE="RS232", RIT=5, FORCE
inaparam_ser1: FORCE,NODENUMBER=2, PORTNUMBER=11159
modemparam_ser1: 57600,n,8,1, RIT=255
modeminit_ser1: STRING=ATS0=1
modemescape_ser1: SEQUENCE=+++
modemdelay_ser1: RESPONSE=2500
[3.1]
[3.100]
moduladr: 0
version: 1.0.0.0
[3.101]
[3.1824]
{3.1856}
klasse: "X20PS9500"
comparam: 
[5.1]
spi: OBJEKTID=2
{5.2}
klasse: "HC_SPS.Class"
familie: 20
modulname: PLC1
[4.1]
spi: OBJEKTID=5
{4.3}
klasse: "HC_Moduluebersicht.Class"
name: _PRJ-Moduluebersicht
[1.1]
[1.100]
moduladr: 1
modulname: CPU
version: 1.0.1.0
prescaler: 5
anschlussgrp: "eth2"
anschlussinfo: NUMMER=1, MODULID=0, FLAGS=0
anschlussgrp: "x2x4"
anschlussinfo: NUMMER=1, MODULID=0, FLAGS=0
[1.101]
[1.1840]
comparam_x2x4: SYNCUSAGE=50, IOSIZE=8, RESPTIME=100, BUSLENGTH=1000, STATIONS=64, ASYNCPAYLOAD=80
timingparam_x2x4: CYCLETIME=2000, PRESCALE=1
[1.1632]
comparam_eth2: IP=192.168.0.99, MASK=255.255.255.0, BROADCAST=255.255.255.255, FORCE
inaparam_eth2: PORTNO=11159, FORCE
cfgparam_eth2: SOCKETCNT=16, DESCRCNT=16, MEMBUFCNT=453, ARPTBLENTRCNT=16, PAGECNT=16, ROUTINGENTRCNT=0, FBSERVERPORT=11159, FBTCPPRI=182, PNADAEMONPRI=184, LIBPRI=183, BROADCASTCNT=5
[1.1824]
{1.108}
klasse: "X20CP0292"
