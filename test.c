#include "COOPS.h"
#include <stdio.h>
#include <string.h>

class(String)
	const char *cString;
	expectMethod(struct classType(String), fromCString, (const char *str))
	// expectMethod(struct classType(String), concat, (struct classType(String) str, struct classType(String) otherStr));
	// expectMethod(struct classType(String), concatCStrings, (const char *str1, const char *str2))
endClass(String)
class(Tester)
	classType(String) msg;
	expectMethod(void, test, ())
endClass(Tester)
class(Meeper)
	expectMethod(void, meep, (classType(String) msg))
	expectMethod(struct classType(Meeper), __init__, ())
endClass(Meeper)

void main(int argc, const char **argv) {

	// INITIALIZATION OF CLASSES //

	// Method String::fromCString(const char *)
	method(String, classType(String), fromCString, (const char *str))
		classType(String) newStr;
		newStr.cString = str;
		return newStr;
	endMethod(String, fromCString)
	// // Method String::concat(String, String)
	// method(String, classType(String), concat, (classType(String) str, classType(String) otherStr))
	// 	classType(String) newStr;
	// 	newStr.cString = str.cString;
	// 	strcat(newStr.cString, otherStr.cString);
	// 	return newStr;
	// endMethod(String, concat)
	// // Method String.concatCStrings(const char *, const char *)
	// method(String, classType(String), concatCStrings, (const char *s1, const char *s2))
	// 	char * restrict resultStr;
	// 	strcat(resultStr, s1);
	// 	strcat(resultStr, s2);
	// 	return String.fromCString((const char *)resultStr);
	// endMethod(String, concatCStrings)
	// Method Tester::test()
	method(Tester, void, test, ())
		puts(Tester.msg.cString);
	endMethod(Tester, test)
	// Method Meeper::__init__()
	method(Meeper, classType(Meeper), __init__, ())
		classType(Meeper) inst = Meeper;
		return inst;
	endMethod(Meeper, __init__)
	// Method Meeper::meep(String)
	method(Meeper, void, meep, (classType(String) msg))
		puts("Meep!");
		puts(msg.cString);
		puts("Meep!");
	endMethod(Meeper, meep)

	// ACTUAL CODE //
	classType(String) theMsg = String.fromCString("Hello!");
	Tester.msg = String.fromCString("Hi!");
	Tester.test();
	classType(Meeper) myMeeper = init(Meeper);
	myMeeper.meep(theMsg);
	Tester.msg = String.fromCString("Hello there, world of OOPS!");
	Tester.test();
}