#include "pch.h"
#include <iostream>
#include "Iddk2000Apis.h"

TEST(IddkGetSdkDescriptionTest, ValidBuffer) {
    int buffCharCnt = 256;
    char infoBuff[256];

    IddkResult result = Iddk_GetSdkDescription(infoBuff, &buffCharCnt);

    printf("Test: UN_02_001.\n");
    EXPECT_EQ(result, IDDK_OK);
    EXPECT_EQ(buffCharCnt, strlen(infoBuff));
}

TEST(IddkGetSdkDescriptionTest, NullBuffer) {
    int buffCharCnt = 256;

    IddkResult result = Iddk_GetSdkDescription(nullptr, &buffCharCnt);

    printf("Test: UN_02_002.\n");
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkGetSdkDescriptionTest, NullSize) {
    char infoBuff[256];

    IddkResult result = Iddk_GetSdkDescription(infoBuff, nullptr);

    printf("Test: UN_02_003.\n");
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkGetSdkDescriptionTest, BufferTooSmall) {
    int buffCharCnt = 10;
    char infoBuff[10];

    IddkResult result = Iddk_GetSdkDescription(infoBuff, &buffCharCnt);

    printf("Test: UN_02_004.\n");
    EXPECT_EQ(result, IDDK_NOT_ENOUGH_BUFFER);
}