# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 16:31:51 2020

@author: Dell
"""
lst1 = ['192.168.1.1', '192.168.10.50' ,'192.168.20.1 ','10.0.0.138']
lst2 = ['25' , '80' , '443' ,' 3000']
servers = []
IP = []
ports = []
def assign(ip,*args,port):
    local = []
    local.append(ip)
    local.append(port)
    for arg in args :
        servers.append(arg)
    return local
     
IP = assign(lst1,'Cold Fusion','Enhydra' , 'Jetty',port = lst2 )[0]
ports = assign(lst1,'Cold Fusion','Enhydra' , 'Jetty',port = lst2 )[1]
print(servers)
print(IP)
print(ports)