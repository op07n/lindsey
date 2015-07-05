# lindsey
A simple browser for the Link2, written in Qt.

## Requirements
* [Qt 5.4](http://www.qt.io/download/) or higher
* [CMake 2.8.11](http://www.cmake.org/download/) or higher
* [libbson](http://api.mongodb.org/libbson/1.1.4/)
* [bson_bind](www.github.com/kipr/bson_bind)
* [daylite](www.github.com/kipr/daylite)

## Building (OS X and Linux)
	cd lindsey
 	mkdir build
 	cd build
 	cmake ..
 	make

## Running
The lindsey executable can be found in the build directory. You can specify a home URL as an argument. For example,

	./lindsey www.kipr.org
	
will run lindsey and display KIPR's website.

## Authors
* Nafis Zaman

## License
lindsey is released under the terms of the GPLv3 license. For more information, see the LICENSE file in the root of this project.
