/*	$OpenBSD: if_gif.h,v 1.16 2017/01/29 19:58:47 bluhm Exp $	*/
/*	$KAME: if_gif.h,v 1.17 2000/09/11 11:36:41 sumikawa Exp $	*/

/*
 * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * if_gif.h
 */

#ifndef _NET_IF_GIF_H_
#define _NET_IF_GIF_H_

struct gif_softc {
	struct ifnet	gif_if;	   /* common area */
	struct sockaddr	*gif_psrc; /* Physical src addr */
	struct sockaddr	*gif_pdst; /* Physical dst addr */
	u_int		gif_rtableid;
	LIST_ENTRY(gif_softc) gif_list;	/* list of all gifs */
};

extern LIST_HEAD(gif_softc_head, gif_softc) gif_softc_list;

int gif_encap(struct ifnet *, struct mbuf **, sa_family_t);

int in_gif_input(struct mbuf **, int *, int);
int in6_gif_input(struct mbuf **, int *, int);

#endif /* _NET_IF_GIF_H_ */
