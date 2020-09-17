//packet.cpp
#include "std.h"

void pack_SetNewMember(MEMBER* pmem)
{
	pmem->flag = PACK_NEWMEMBER;
}

void pack_SetLogin(LOGIN* plogin)
{
	plogin->flag = PACK_LOGIN;
}

void pack_SetLogout(LOGIN* plogin)
{
	plogin->flag = PACK_LOGOUT;
}

void pack_SetDeleteMember(LOGIN* pmem)
{
	pmem->flag = PACK_DELETEMEMBER;
}
