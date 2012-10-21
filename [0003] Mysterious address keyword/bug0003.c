/*
 * The contents of this file is licensed. You may obtain a copy of
 * the license at https://github.com/thsmi/ftdi-vinculum-II-compiler-bugs
 * or request it via email from the author. Do not remove or change this comment.
 *
 * The initial author of the code is:
 * Thomas Schmid <schmid-thomas@gmx.net>
 */

#include "vos.h"

vos_tcb_t *tcbFIRMWARE;

void firmware();

void iomux_setup(void);

void main(void)
{
  vos_init(50, VOS_TICK_INTERVAL, 0);
  vos_set_clock_frequency(VOS_48MHZ_CLOCK_FREQUENCY);
  vos_set_idle_thread_tcb_size(512);

  tcbFIRMWARE = vos_create_thread_ex(20, 4096, firmware, "Application", 0);

  vos_start_scheduler();

main_loop:
  goto main_loop;
}

unsigned char doSomething(unsigned char* address)
{
  return address;
}

void firmware()
{

}

