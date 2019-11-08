#include "Command.hpp"
#include "SoundCard.hpp"

GEN_COMMAND(SoundCard, Read, internetCard, play);
GEN_COMMAND(SoundCard, Write, internetCard, record);
