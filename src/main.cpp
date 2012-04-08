/*
 * main.cpp
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
#include <boost/program_options.hpp>
#include <string>

namespace po = boost::program_options;

int main(int argc, char** argv) {
	po::options_description options;
	options.add_options()
			("address,a", po::value<std::string>()->default_value("224.0.0.251"), "multicast address")
			("port,p", po::value<int>()->default_value(5353), "Port to xmit on")
			("help,h", "print this message");

	po::variables_map map;
	try {
		po::store(po::parse_command_line(argc, argv, options), map);
		po::notify(map);
	} catch (const po::invalid_option_value& e) {
		std::cerr << "Invalid value for: " << e.get_option_name() << std::endl;
	} catch (const po::multiple_values& e){
		std::cerr << "Too many values for: " << e.get_option_name() << std::endl;
	} catch (const po::unknown_option& e){
		std::cerr << "Unknown option: " << e.get_option_name() << std::endl;
	}

	if (map.count("help")) {
		options.print(std::cout);
		return 0;
	}



	return 0;
}

