// mlsdata.h
// данные М-последовательности (последовательности максимальной длины)
// Maximum Length Sequence (MLS)

#ifndef MLSDATA_H
#define MLSDATA_H

struct MLSData
{
//    MLSData() {};
    uint32_t initSeq {0}; // initial sequence - начальная последовательность
    uint32_t polynominal {0}; // полином
    uint16_t length {0}; // длина последовательности
    uint32_t sequence {0}; // полученная последовательность
    double peakSideLobe {0}; // уровень боковых лепестков АКФ
    double meritFactor {0}; // уровень боковых лепестков АКФ
};

#endif // MLSDATA_H
