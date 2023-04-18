#include "kernel/system.h"


int do_chrt(struct proc * caller, message * m_ptr)
{
  long deadline;
  char new_priority;

#ifndef DEFAULT_QUEUE_NR
#define DEFAULT_QUEUE_NR  7
#endif

  deadline = m_ptr->m_pm_chrt.deadline;
  deadline = (deadline >= 0) ? deadline:0; /* avoid negative number */
  caller->deadline = deadline;

  new_priority = (deadline < DEFAULT_QUEUE_NR) ? deadline:DEFAULT_QUEUE_NR-1;
  assert(new_priority>=0 && new_priority<DEFAULT_QUEUE_NR);
  caller->p_priority = new_priority;

  return (OK);
}