//control.h

#pragma once

void con_init();
void con_exit();

void con_netmember();
void con_login();
void con_logout();
void con_delete();

void con_RecvData(char* buf);