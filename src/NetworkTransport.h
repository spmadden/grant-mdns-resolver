/*
 * NetworkTransport.h
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

#ifndef NETWORKTRANSPORT_H_
#define NETWORKTRANSPORT_H_

namespace grant {

/*
 * This interface represents a transport layer for the DNS queries.
 */
class NetworkTransport {
public:
	virtual ~NetworkTransport(){};

	/*
	 * Transmits a packet on the wire.
	 * @param 1 - pointer to a byte array
	 * @param 2 - size of the byte array
	 * @returns true if the send is successful.
	 */
	virtual bool transmit(const uint8_t*, const std::size_t) = 0;

	/*
	 * Receives a packet from the wire and loads it into the array
	 * @param 1 - pointer to a byte array
	 * @param 2 - size of the byte array
	 * @returns the number of bytes received
	 */
	virtual std::size_t receive(uint8_t*, std::size_t) = 0;
};

} /* namespace grant */
#endif /* NETWORKTRANSPORT_H_ */
