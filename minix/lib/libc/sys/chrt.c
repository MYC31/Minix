#include <sys/cdefs.h>
#include "namespace.h"
#include <lib.h>


int chrt(long deadline)
{
    message m;

    memset(&m, 0, sizeof(m));
    m.m_pm_chrt.deadline = deadline;
    return(_syscall(PM_PROC_NR, PM_CHRT, &m));
}