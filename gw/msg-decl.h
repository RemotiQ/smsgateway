/* ==================================================================== 
 * The Kannel Software License, Version 1.0 
 * 
 * Copyright (c) 2001-2009 Kannel Group  
 * Copyright (c) 1998-2001 WapIT Ltd.   
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in 
 *    the documentation and/or other materials provided with the 
 *    distribution. 
 * 
 * 3. The end-user documentation included with the redistribution, 
 *    if any, must include the following acknowledgment: 
 *       "This product includes software developed by the 
 *        Kannel Group (http://www.kannel.org/)." 
 *    Alternately, this acknowledgment may appear in the software itself, 
 *    if and wherever such third-party acknowledgments normally appear. 
 * 
 * 4. The names "Kannel" and "Kannel Group" must not be used to 
 *    endorse or promote products derived from this software without 
 *    prior written permission. For written permission, please  
 *    contact org@kannel.org. 
 * 
 * 5. Products derived from this software may not be called "Kannel", 
 *    nor may "Kannel" appear in their name, without prior written 
 *    permission of the Kannel Group. 
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED.  IN NO EVENT SHALL THE KANNEL GROUP OR ITS CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 * ==================================================================== 
 * 
 * This software consists of voluntary contributions made by many 
 * individuals on behalf of the Kannel Group.  For more information on  
 * the Kannel Group, please see <http://www.kannel.org/>. 
 * 
 * Portions of this software are based upon software originally written at  
 * WapIT Ltd., Helsinki, Finland for the Kannel project.  
 */ 

/*
 * msg-decl.h - message declarations
 *
 * This file contains declarations of the message types. See the
 * architecture document to see how these should be interpreted and
 * modified.
 *
 * This file is included by a number of other files.
 *
 * Lars Wirzenius
 */

MSG(heartbeat,
    {
        INTEGER(load)
    })

MSG(admin,
    {
        INTEGER(command)
        OCTSTR(boxc_id)
    })
    
MSG(sms,
    {
        OCTSTR(sender)
        OCTSTR(receiver)
        OCTSTR(udhdata)
        OCTSTR(msgdata)
        INTEGER(time)
        OCTSTR(smsc_id)
        OCTSTR(smsc_number)
        OCTSTR(foreign_id)
        OCTSTR(service)
        OCTSTR(account)
        UUID(id)
        INTEGER(sms_type)
        INTEGER(mclass)
        INTEGER(mwi)
        INTEGER(coding)
        INTEGER(compress)
        INTEGER(validity)
        INTEGER(deferred)
        INTEGER(dlr_mask)
        OCTSTR(dlr_url)
        INTEGER(pid)
        INTEGER(alt_dcs)
        INTEGER(rpi)
        OCTSTR(charset)
        OCTSTR(boxc_id)
        OCTSTR(binfo)
        INTEGER(msg_left)
        VOID(split_parts)
        INTEGER(priority)
        INTEGER(resend_try)
        INTEGER(resend_time)
        OCTSTR(meta_data)
    })

MSG(ack,
    {
        INTEGER(nack)
        INTEGER(time)
        UUID(id)
    })
    
MSG(wdp_datagram,
    {
        OCTSTR(source_address)
        INTEGER(source_port)
        OCTSTR(destination_address)
        INTEGER(destination_port)
        OCTSTR(user_data)
    })

#undef MSG
#undef INTEGER
#undef OCTSTR
#undef UUID
#undef VOID
