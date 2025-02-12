#include <iostream>
#include <cstdint>

#define NO_OF_KEYS 40
#define NO_OF_STRINGS 64

uint16_t offsets[NO_OF_KEYS];
uint16_t stringOffsets[NO_OF_STRINGS];

uint8_t data[] = {
    0x00,
    0x43,
    0x92,
    0x93,
    0x92,
    0x01,
    0x02,
    0x03,
    0x00,
    0x00,
    0x00,
    0x84,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    254, 11, 72, 97, 114, 100, 105, 107, 32, 74, 97, 105, 110, 23, 106, 97, 105, 110, 104, 97, 114, 100, 105, 107, 49, 50, 48, 64, 103, 109, 97, 105, 108, 46, 99, 111, 109, 15, 86, 97, 115, 104, 110, 105, 32, 65, 103, 114, 97, 104, 97, 114, 105, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255};

uint8_t *readAction(uint8_t *temp)
{
    if ((*temp & 0xc0) == 0x00)
    {
        temp++;
    }
    else if ((*temp & 0xc0) == 0x40)
    {
        uint8_t no_of_actions = (*temp & 0x3f);
        temp++;
        while (no_of_actions--)
        {
            temp = readAction(temp);
        }
    }
    else if ((*temp & 0xf8) == 0x80)
    {
        temp += (*temp & 0x07);
        temp++;
    }
    else if ((*temp) == 0x91)
    {
        temp += 3;
    }
    else if (((*temp & 0xfc) == 0x88))
    {
        temp += 2;
    }
    else
    {
        temp++;
    }
    return temp;
}

void readData()
{
    uint8_t *temp = data;
    uint16_t *offsetPointer = offsets;
    while (*temp != 0xfe)
    {
        *offsetPointer = (temp - data);
        offsetPointer++;
        temp = readAction(temp);
    }
    temp++;
    uint16_t *stringOffsetPointer = stringOffsets;
    while (*temp != 0xff)
    {
        *stringOffsetPointer = (temp - data);
        stringOffsetPointer++;
        temp += (*temp);
        temp++;
    }

    for (uint8_t i = 0; i < 40; i++)
    {
        std::cout << offsets[i] << "\n";
    }
}

int main()
{
    readData();
}