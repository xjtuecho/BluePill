# VCOMCAN 固件说明

VCOMCAN固件是一个强大的CANFD调试软件，运行在BluePill开发板上，要求主控芯片为老版本GD32E103C8T6或者GD32C103C8T6，配合专用底板，可以作为CANFD的调试工具使用。

## 使用方法

使用GDLink或者JLink将hex文件烧录到BluePill开发板，注意按照实际晶振频率选择固件，目前提供8M和12M晶振固件。连接BluePill的USB接口或者PA9/PA10物理串口，均可以使用VCOMCAN固件所有功能。

上位机推荐使用超级终端(HyterTerminal).

## 命令手册

### version 查看固件信息

```
version
 VCOMCAN v24.6.5 SN:44103153514A095248544437
 ECHO Studio <echo.xjtu@gmail.com>. All Rights Reserved.
```

## help 查看在线帮助

```
help
 can -> can [baud|mode|speed|clear] CAN port setup.
 std -> std [hexID] [hexDATA|remote] Send standard data/remote message.
 ext -> ext [hexID] [hexDATA|remote] Send extended data/remote message.
 env -> env [ch|show|add|txfd|txt|cnt|prd] Set/Show environment variables.
 uart -> uart [baud|mode|addr] UART port setup.
 filter -> filter [0-7] [mode|scale|act|r0|r1] [param] CAN filter setup.
 param -> param [load|save|restore] Operate parameters.
 reboot -> reboot [delay ms] Restart system.
 help -> help Info.
 version -> display SW version and SN.
```

## can 查看和设置CAN参数

```
can
can [baud|mode|speed|clear] CAN port setup.
 CH0 BAUD=0k FDBAUD=2M FDEN=1 MODE=0 Normal
 RX0 OK=0 LOST=0
 TX0 OK=3 LOST=0
```

### can baud 设置CAN波特率，单位kbps

```
can baud
 can baud [baud in kbps] set CAN baudrate.
 CH0 BAUD=500k FDBAUD=2M
can baud 1000
 CH0 BAUD=1000k FDBAUD=2M
```

### can fdbaud 设置CANFD波特率，单位Mbps，范围1-6M

```
can fdbaud
 can baud [baud in kbps] set CAN baudrate.
 CH0 BAUD=500k FDBAUD=2M
can fdbaud 5
 CH0 BAUD=500k FDBAUD=5M
```

### can speed 查看过去一段时间总线速度

```
can speed
Oldest
     0      0      0      0      0      0      0      0
     0      0      0      0      0      0      0      0
     0      0      0      0      0      0      0      0
     0      0      0      0      0      0      0      0
     0      0      0      0      0      0      0      0
     0      0      0      0      0      0      0      0
     0      0      0      0      0      0      0      0
     0      0      0      0      0      0      0      0
                                                      Newest
CAN0 RX speed at last 64 seconds. MIN=0fps MAX=0fps
```

## std和ext 发送标准帧或者扩展帧

```
std 11 22334455
 TX0:00000006 DATA MSG ID=0x0011 LEN=4 DATA=22 33 44 55
 RX1:00000006 DATA MSG ID=0x0011 LEN=4 DATA=22 33 44 55
ext 22 1122334455667788
 TX0:00000007 DATA MSG ID=0x00000022 LEN=8 DATA=11 22 33 44 55 66 77 88
 RX1:00000007 DATA MSG ID=0x00000022 LEN=8 DATA=11 22 33 44 55 66 77 88
```

默认发送CAN帧，如果env命令设置TXFD=1，那么发送FD帧，FD帧的DATA部分会换行显示

```
env txfd 1
 TXFD=1
env
env [ch|show|add|txfd|txt|cnt|prd] Set/Show environment variables.
 CH=0 SHOW=1 ADD=0 SINGLE=0 TXFD=1 BRS=1 TXT=0 CNT=1 PRD=0us
std 11 22334455
 TX0:00000008 DATA MSG ID=0x0011 LEN=4 DATA=
 22 33 44 55
 RX1:00000008 DATA MSG ID=0x0011 LEN=4 DATA=
 22 33 44 55
ext 11 1122334455667788AABBCCDD
 TX0:00000009 DATA MSG ID=0x00000011 LEN=12 DATA=
 11 22 33 44 55 66 77 88 AA BB CC DD
 RX1:00000009 DATA MSG ID=0x00000011 LEN=12 DATA=
 11 22 33 44 55 66 77 88 AA BB CC DD
```

## env 查看和设置环境变量

通过环境变量来控制参数。

```
env
env [ch|show|add|txfd|txt|cnt|prd] Set/Show environment variables.
 CH=0 SHOW=1 ADD=0 SINGLE=0 TXFD=0 BRS=1 TXT=0 CNT=1 PRD=0us
env ch 1
 CH=1
env ch 0
 CH=0
```

环境变量说明如下：

- CH，取值0/1，当前操作的通道
- SHOW，取值0/1，是否在UART上显示收发数据帧
- ADD，取值0/1，发送时帧ID是否增加
- SINGLE，取值0/1，是否单次发送
- TXFD，取值0/1，是否发送FD帧
- BRS，取值0/1，数据段是否切换
- TXT，取值0/1，是否文本方式收发
- CNT，单次发送次数
- PRD，发送间隔，单位为us，0表示连续发送
