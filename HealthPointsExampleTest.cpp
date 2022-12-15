
#include <sstream>

#include "HealthPoints.h"

namespace HealthPointsTests {

static bool checkHealthPointsValues(const HealthPoints& healthPoints, int current, int max)
{
	std::ostringstream expected;
	expected << current << '(' << max << ')';
	std::ostringstream result;
	result << healthPoints;
	return (expected.str() == result.str());
}

bool testInitialization()
{
	std::cout << "initialization" << std::endl;
	bool testResult = true;

	HealthPoints healthPoints1; /* has 100 points out of 100 */
	HealthPoints healthPoints2(150); /* has 150 points out of 150 */
	bool exceptionThrown = false;
	try {
		HealthPoints healthPoints3(-100);
	}
	catch (HealthPoints::InvalidArgument& e) {
		exceptionThrown = true;
	}

	testResult = testResult && exceptionThrown;
	testResult = testResult && checkHealthPointsValues(healthPoints1, 100, 100);
	return testResult;
}

bool testArithmaticOperators()
{
	std::cout << "arithmacy" << std::endl;

	bool testResult = true;
	HealthPoints healthPoints1; /* has 100 points out of 100 */
	std::cout << "1 init" << std::endl;
	HealthPoints healthPoints2(150); /* has 150 points out of 150 */
	std::cout << "2 init" << std::endl;
	std::cout << "result 0 is " << testResult << std::endl;

	healthPoints1 -= 20; /* now has 80 points out of 100 */
	testResult = testResult && checkHealthPointsValues(healthPoints1, 80, 100);
	std::cout << "result 1 is " << testResult << std::endl;

	healthPoints1 += 100; /* now has 100 points out of 100 */
	testResult = testResult && checkHealthPointsValues(healthPoints1, 100, 100);
	std::cout << "result 2 is " << testResult << std::endl;

	healthPoints1 -= 150; /* now has 0 points out of 100 */
	testResult = testResult && checkHealthPointsValues(healthPoints1, 0, 100);
	std::cout << "result 3 is " << testResult << std::endl;

	healthPoints2 = healthPoints2 - 160; /* now has 0 points out of 150 */
	testResult = testResult && checkHealthPointsValues(healthPoints2, 0, 150);
	std::cout << "result 4 is " << testResult << std::endl;

	healthPoints2 = 160 + healthPoints1; /* now has 100 out of 100 */
	testResult = testResult && checkHealthPointsValues(healthPoints2, 100, 100);

	return testResult;

}

bool testComparisonOperators()
{
	std::cout << "comparison" << std::endl;
	bool testResult = true;
	HealthPoints healthPoints1 = HealthPoints(100); /* has 100 points out of 100 */
	HealthPoints healthPoints2 = 100; /* has 100 points out of 100 */
	bool comparisonResult;

	comparisonResult = (healthPoints1 == healthPoints2); /* returns true */
	testResult = testResult && comparisonResult;

	healthPoints2 = HealthPoints(150); /* has 150 points out of 150 */
	comparisonResult = (healthPoints1 == healthPoints2); /* returns false */
	testResult = testResult && !comparisonResult;

	healthPoints2 -= 50; /* now has 100 points out of 150 */
	comparisonResult = (healthPoints1 == healthPoints2); /* returns true */

	comparisonResult = (healthPoints1 < healthPoints2); /* returns false */
	testResult = testResult && !comparisonResult;

	healthPoints1 -= 50; /* now has 50 points out of 100 */
	comparisonResult = (healthPoints1 < healthPoints2); /* returns true */

	return testResult;
}

bool testOutputOperator()
{
	std::cout << "output" << std::endl;
	bool testResult = true;
	std::ostringstream stream;

	HealthPoints healthPoints1 = HealthPoints(100); /* has 100 points out of 100 */
	healthPoints1 -= 50; /* now has 50 points out of 100 */
	stream << healthPoints1; /* stream content is "50(100)" */
	testResult = testResult && (stream.str() == "50(100)");

	HealthPoints healthPoints2 = HealthPoints(150); /* has 1500 points out of 150 */
	healthPoints2 -= 50; /* now has 100 points out of 150 */
	stream << ", " << healthPoints2; /* stream content is "50(100), 100(150)" */
	testResult = testResult && (stream.str() == "50(100), 100(150)");

	return testResult;
}

}
