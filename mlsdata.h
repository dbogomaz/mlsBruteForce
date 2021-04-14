// mlsdata.h
// данные М-последовательности (последовательности максимальной длины)
// Maximum Length Sequence (MLS)

#ifndef MLSDATA_H
#define MLSDATA_H

struct MLSData
{
//    MLSData() {};
    uint32_t init_seq {0}; // initial sequence - начальная последовательность
    uint32_t polynominal {0}; // полином
    uint16_t length {0}; // длина последовательности
    uint32_t sequence {0}; // полученная последовательность
    uint32_t acf {0}; // autocorrelation function - автокорреляционная функция
    int32_t acf_peak_side_lobe {0}; // уровень боковых лепестоков АКФ
};

#endif // MLSDATA_H
