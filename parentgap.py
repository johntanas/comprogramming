import datetime as dt
t=int(input())
m=dt.datetime(t,5,1)
if m.weekday()>3:
    print("6 weeks")
else:
    print("5 weeks")