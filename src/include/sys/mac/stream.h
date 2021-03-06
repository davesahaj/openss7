/*****************************************************************************

 @(#) src/include/sys/mac/stream.h

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation; version 3 of the License.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 *****************************************************************************/

#ifndef __SYS_MAC_STREAM_H__
#define __SYS_MAC_STREAM_H__

#ifndef __SYS_STREAM_H__
#warning "Do not include sys/mac/stream.h directly, include sys/stream.h instead."
#endif

#ifndef __KERNEL__
#error "Do not include kernel header files in user space programs."
#endif

#ifndef __EXTERN_INLINE
#define __EXTERN_INLINE extern __inline__
#endif

#ifndef __MAC_EXTERN_INLINE
#define __MAC_EXTERN_INLINE __EXTERN_INLINE streamscall
#endif

#ifndef __MAC_EXTERN
#define __MAC_EXTERN extern streamscall
#endif

#ifndef _MAC_SOURCE
#warning "_MAC_SOURCE not defined but MAC stream.h included."
#endif

#include <sys/openss7/config.h>

#if defined CONFIG_STREAMS_COMPAT_MAC || defined CONFIG_STREAMS_COMPAT_MAC_MODULE

#ifndef dev_t
#define dev_t __streams_dev_t
#endif

/* These are MPS definitions exposed by MacOT, but implemented in mpscompat.c */

__MAC_EXTERN mblk_t *mi_timer_alloc_MAC(queue_t *q, size_t size);
__MAC_EXTERN void mi_timer_MAC(mblk_t *mp, clock_t msec);
__MAC_EXTERN void mi_timer_ticks(mblk_t *mp, clock_t ticks);
__MAC_EXTERN int mi_timer_cancel(mblk_t *mp);
__MAC_EXTERN mblk_t *mi_timer_q_switch(mblk_t *mp, queue_t *q, mblk_t *new_mp);
__MAC_EXTERN int mi_timer_valid(mblk_t *mp);
__MAC_EXTERN int mi_timer_requeue(mblk_t *mp);
__MAC_EXTERN void mi_timer_free(mblk_t *mp);
__MAC_EXTERN unsigned long mi_timer_remain(mblk_t *mp);
__MAC_EXTERN int mi_timer_running(mblk_t *mp);
__MAC_EXTERN int mi_timer_cond(mblk_t *mp, clock_t msec);

__MAC_EXTERN queue_t *mi_allocq(struct streamtab *st);

__MAC_EXTERN mblk_t *mi_reuse_proto(mblk_t *mp, size_t size, int keep_on_error);
__MAC_EXTERN mblk_t *mi_reallocb(mblk_t *mp, size_t size);

__MAC_EXTERN uint8_t *mi_offset_param(mblk_t *mp, size_t offset, size_t len);
__MAC_EXTERN uint8_t *mi_offset_paramc(mblk_t *mp, size_t offset, size_t len);

__MAC_EXTERN int mi_set_sth_hiwat(queue_t *q, size_t size);
__MAC_EXTERN int mi_set_sth_lowat(queue_t *q, size_t size);
__MAC_EXTERN int mi_set_sth_maxblk(queue_t *q, ssize_t size);
__MAC_EXTERN int mi_set_sth_wroff(queue_t *q, size_t size);

__MAC_EXTERN caddr_t mi_next_ptr(caddr_t ptr);
__MAC_EXTERN caddr_t mi_prev_ptr(caddr_t ptr);
__MAC_EXTERN caddr_t mi_open_detached(caddr_t *mi_list, size_t size, dev_t *devp);
__MAC_EXTERN void mi_attach(queue_t *q, caddr_t ptr);
__MAC_EXTERN int mi_open_comm(caddr_t *mi_list, size_t size, queue_t *q, dev_t *dev, int flag, int sflag, cred_t *credp);
__MAC_EXTERN void mi_detach(queue_t *q, caddr_t ptr);
__MAC_EXTERN void mi_close_detached(caddr_t *mi_list, caddr_t strptr);
__MAC_EXTERN int mi_close_comm(caddr_t *mi_list, queue_t *q);

__MAC_EXTERN void mi_bufcall(queue_t *q, int size, int priority);

__MAC_EXTERN void mi_copyin(queue_t *q, mblk_t *mp, caddr_t uaddr, size_t len);
__MAC_EXTERN void mi_copyout(queue_t *q, mblk_t *mp);
__MAC_EXTERN mblk_t *mi_copyout_alloc(queue_t *q, mblk_t *mp, caddr_t uaddr, size_t len, int free);
__MAC_EXTERN void mi_copy_done(queue_t *q, mblk_t *mp, int err);
__MAC_EXTERN int mi_copy_state(queue_t *q, mblk_t *mp, mblk_t **mpp);
__MAC_EXTERN void mi_copy_set_rval(mblk_t *mp, int rval);

#define mi_timer_alloc(_q,_size)	mi_timer_alloc_MAC(_q,_size)
#define mi_timer(_mp,_msec)		mi_timer_MAC(_mp,_msec)

#else
#ifdef _MAC_SOURCE
#warning "_MAC_SOURCE defined by not CONFIG_STREAMS_COMPAT_MAC"
#endif
#endif

#endif				/* __SYS_MAC_STREAM_H__ */
