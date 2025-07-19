extern "C" {
#include "dht11.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(DHT11_C_API_Tests)
{
    void setup() {}
    void teardown() {
        mock().clear();
    }
};

TEST(DHT11_C_API_Tests, ReadShouldReturnSuccess)
{
    int result = dht11_read();
    CHECK_EQUAL(0, result); // 0 means success in this case
}

TEST(DHT11_C_API_Tests, TemperatureShouldBeInRange)
{
    dht11_read();
    int temp = dht11_get_temperature();
    CHECK_TRUE(temp >= 0 && temp <= 50); // DHT11 typical range
}

TEST(DHT11_C_API_Tests, HumidityShouldBeInRange)
{
    dht11_read();
    int hum = dht11_get_humidity();
    CHECK_TRUE(hum >= 20 && hum <= 90); // DHT11 typical range
}

TEST(DHT11_C_API_Tests, ReadFailsReturnsErrorCode)
{
    // You would mock this if needed
    // For now, assume 1 means failure
    int result = dht11_read();
    if (result != 0) {
        int temp = dht11_get_temperature();
        int hum = dht11_get_humidity();
        CHECK_EQUAL(-1, temp);
        CHECK_EQUAL(-1, hum);
    }
}
