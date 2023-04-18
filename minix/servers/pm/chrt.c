#include "pm.h"


int do_chrt()
{
  long deadline;

  deadline= m_in.m_pm_chrt.deadline;
  return(sys_chrt(deadline));
}