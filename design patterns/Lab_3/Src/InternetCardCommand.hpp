#include "Command.hpp"
#include "InternetCard.hpp"

GEN_COMMAND(InternetCard, Read, internetCard, sendIn);
GEN_COMMAND(InternetCard, Write, internetCard, recvFrom);
