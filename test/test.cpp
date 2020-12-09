#include "gtest/gtest.h"
#include "stateTests.h"
#include "taskTests.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
