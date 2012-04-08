/*
 * RecordParser.h
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

#ifndef RECORDPARSER_H_
#define RECORDPARSER_H_

namespace grant {

/*
 * The record parser interface provides a method of encoding and decoding
 * DNS Record Types
 */
class RecordParser {
public:
	virtual ~RecordParser(){};

	virtual std::string encode() const = 0;
	virtual bool decode(const std::string&) = 0;

	virtual int getType() const = 0;
	virtual std::string getName() const = 0;

};

} /* namespace grant */
#endif /* RECORDPARSER_H_ */
