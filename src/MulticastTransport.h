/*
 * MulticastTransport.h
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

#ifndef MULTICASTTRANSPORT_H_
#define MULTICASTTRANSPORT_H_

#include "NetworkTransport.h"

// forward defines.
namespace boost{
namespace asio{
class io_service;
namespace ip{
class udp;
class udp::socket;
}
}
}
namespace aip = boost::asio::ip;

namespace grant {

class MulticastTransport : public NetworkTransport{
public:

	/*
	 * Constructs a new MulticastTransport agent
	 * @param 1 - string IPv4 address in dotted-decimal
	 * @param 2 - uint32_t port
	 */
	MulticastTransport(const std::string&, uint32_t);
	virtual ~MulticastTransport();

	/*
	 * Transmits a packet on the wire.
	 * @param 1 - pointer to a byte array
	 * @param 2 - size of the byte array
	 * @returns true if the send is successful.
	 */
	virtual bool transmit(const uint8_t*, const std::size_t);

	/*
	 * Receives a packet from the wire and loads it into the array
	 * @param 1 - pointer to a byte array
	 * @param 2 - size of the byte array
	 * @returns the number of bytes received
	 */
	virtual std::size_t receive(uint8_t*, std::size_t);

private:
	boost::asio::io_service _ioservice;
	aip::udp::socket _socket;

};

} /* namespace grant */
#endif /* MULTICASTTRANSPORT_H_ */
