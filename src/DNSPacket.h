/*
 * DNSPacket.h
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

#ifndef DNSPACKET_H_
#define DNSPACKET_H_

#include <string>
#include <stdint.h>
#include <vector>

namespace grant {

class DNSPacket {
public:
	enum OpCode{
		QUERY = 0,
		IQUERY = 1,
		STATUS = 2,
		NOTIFY = 4,
		UPDATE = 5
	};
	enum Flags{
		RESPONSE = 16,
		AUTHORITATIVE = 11,
		TRUNCATION = 10
	};
	enum ResponseCode{
		NOERROR = 0,
		FORMATERROR = 1,
		SERVERFAILURE = 2,
		NAMEERROR = 3,
		NOTIMPLEMENTED = 4,
		REFUSED = 5,
		YXDOMAIN = 6,
		YXRRSET = 7,
		NXRRSET = 8,
		NOTAUTH = 9,
		NOTZONE = 10
	};
	enum QClass{
		IN = 1,
		CS = 2,
		CH = 3,
		HS = 4,
		ANY = 255,
	};

	typedef struct question_t{
		std::string name;
		uint16_t qtype;
		QClass qclass;
	} Question;

	DNSPacket();
	DNSPacket(const DNSPacket&);
	virtual ~DNSPacket();

	void addQuestion(const Question&);

	bool deserialize(const uint8_t*, const std::size_t);
	bool serialize(uint8_t*, const std::size_t) const;

	bool isQuestion() const;

	uint16_t getFlags() const{return _flags;}
	void setFlags(uint16_t);

	OpCode getOpCode() const{return _opCode;}

private:
	std::vector<std::string> _queries;
	uint16_t _id;
	OpCode _opCode;
	uint16_t _flags;

};

} /* namespace grant */
#endif /* DNSPACKET_H_ */
