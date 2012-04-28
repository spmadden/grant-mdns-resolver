/*
 * MulticastTransport.cpp
 *
 *    Copyright (C) 2012 Sean P Madden
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *    If you would like to license this code under the GNU LGPL, please see
 *    http://www.seanmadden.net/licensing for details.
 *
 */

#include "MulticastTransport.h"

#include <boost/asio/ip/udp.hpp>
#include <boost/asio/ip/multicast.hpp>

namespace grant {

MulticastTransport::MulticastTransport(const std::string& addr, uint32_t port):
	_ioservice(), _socket(_ioservice)
	{
	try{
		aip::address multicast_address =
		  aip::address::from_string(addr);
		aip::multicast::join_group group(multicast_address);
		_socket.set_option(group);

		boost::asio::socket_base::reuse_address reuse_addr(true);
		_socket.set_option(reuse_addr);
	}catch(const boost::system::system_error& e){

	}
}

MulticastTransport::~MulticastTransport() {
}

} /* namespace grant */
