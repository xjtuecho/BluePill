# VCOMCAN �̼�˵��

VCOMCAN�̼���һ��ǿ���CANFD���������������BluePill�������ϣ�Ҫ������оƬΪ�ϰ汾GD32E103C8T6����GD32C103C8T6�����ר�õװ壬������ΪCANFD�ĵ��Թ���ʹ�á�

## ʹ�÷���

ʹ��GDLink����JLink��hex�ļ���¼��BluePill�����壬ע�ⰴ��ʵ�ʾ���Ƶ��ѡ��̼���Ŀǰ�ṩ8M��12M����̼�������BluePill��USB�ӿڻ���PA9/PA10�����ڣ�������ʹ��VCOMCAN�̼����й��ܡ�

��λ���Ƽ�ʹ�ó����ն�(HyterTerminal).

## �����ֲ�

### version �鿴�̼���Ϣ

```
version
 VCOMCAN v24.6.5 SN:44103153514A095248544437
 ECHO Studio <echo.xjtu@gmail.com>. All Rights Reserved.
```

## help �鿴���߰���

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

## can �鿴������CAN����

```
can
can [baud|mode|speed|clear] CAN port setup.
 CH0 BAUD=0k FDBAUD=2M FDEN=1 MODE=0 Normal
 RX0 OK=0 LOST=0
 TX0 OK=3 LOST=0
```

### can baud ����CAN�����ʣ���λkbps

```
can baud
 can baud [baud in kbps] set CAN baudrate.
 CH0 BAUD=500k FDBAUD=2M
can baud 1000
 CH0 BAUD=1000k FDBAUD=2M
```

### can fdbaud ����CANFD�����ʣ���λMbps����Χ1-6M

```
can fdbaud
 can baud [baud in kbps] set CAN baudrate.
 CH0 BAUD=500k FDBAUD=2M
can fdbaud 5
 CH0 BAUD=500k FDBAUD=5M
```

### can speed �鿴��ȥһ��ʱ�������ٶ�

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

## std��ext ���ͱ�׼֡������չ֡

```
std 11 22334455
 TX0:00000006 DATA MSG ID=0x0011 LEN=4 DATA=22 33 44 55
 RX1:00000006 DATA MSG ID=0x0011 LEN=4 DATA=22 33 44 55
ext 22 1122334455667788
 TX0:00000007 DATA MSG ID=0x00000022 LEN=8 DATA=11 22 33 44 55 66 77 88
 RX1:00000007 DATA MSG ID=0x00000022 LEN=8 DATA=11 22 33 44 55 66 77 88
```

Ĭ�Ϸ���CAN֡�����env��������TXFD=1����ô����FD֡��FD֡��DATA���ֻỻ����ʾ

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

## env �鿴�����û�������

ͨ���������������Ʋ�����

```
env
env [ch|show|add|txfd|txt|cnt|prd] Set/Show environment variables.
 CH=0 SHOW=1 ADD=0 SINGLE=0 TXFD=0 BRS=1 TXT=0 CNT=1 PRD=0us
env ch 1
 CH=1
env ch 0
 CH=0
```

��������˵�����£�

- CH��ȡֵ0/1����ǰ������ͨ��
- SHOW��ȡֵ0/1���Ƿ���UART����ʾ�շ�����֡
- ADD��ȡֵ0/1������ʱ֡ID�Ƿ�����
- SINGLE��ȡֵ0/1���Ƿ񵥴η���
- TXFD��ȡֵ0/1���Ƿ���FD֡
- BRS��ȡֵ0/1�����ݶ��Ƿ��л�
- TXT��ȡֵ0/1���Ƿ��ı���ʽ�շ�
- CNT�����η��ʹ���
- PRD�����ͼ������λΪus��0��ʾ��������
