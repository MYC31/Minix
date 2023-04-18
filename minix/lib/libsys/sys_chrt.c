#include "syslib.h"


int 
sys_chrt(long deadline)
{
  message m;

  memset(&m, 0, sizeof(m));
  m.m_pm_chrt.deadline = deadline;
  return(_kernel_call(SYS_CHRT, &m));
}