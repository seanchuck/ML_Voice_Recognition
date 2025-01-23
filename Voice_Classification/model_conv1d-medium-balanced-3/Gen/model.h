/*
* DEEPCRAFT Studio 5.2.2135+b54b28f236fe7c6fb520f00b8de0ba1419f4422f
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 01/23/2025 18:21:57 UTC. Any changes will be lost.
* 
* Model ID  3c8059b9-ae76-4375-a8ad-3c745797feb4
* 
* Memory    Size                      Efficiency
* Buffers   9600 bytes (RAM)          100 %
* State     11592 bytes (RAM)         100 %
* Readonly  103284 bytes (Flash)      100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-medium-balanced-3
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | Kyle
* 2           | Sean
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [512]           float      dequeue
*    window_shape = [512]
*    stride = 160
*    buffer_multiplier = 1
* Hamming smoothing              [512]           float      dequeue
*    sym = True
* Real Discrete Fourier Transform [257,2]         float      dequeue
*    axis = 0
* Frobenius norm                 [257]           float      dequeue
*    axis = 0
* Mel Filterbank                 [40]            float      dequeue
*    num_filters = 40
*    sample_rate = 16000
*    f_low = 300
*    f_high = 8000
* Add Constant                   [40]            float      dequeue
*    A = 1
* Logarithm                      [40]            float      dequeue
* Clip                           [40]            float      dequeue
*    min = 0
*    max = 4
* Imagimob Speech Features       [40]            float      dequeue
*    output_freq = 100
*    output_features = 40
*    low_cut_freq = 300
*    high_cut_freq = 8000
* Sliding Window (data points)   [50,40]         float      dequeue
*    window_shape = [50,40]
*    stride = 280
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [50,40]         float      dequeue
*    contextual_length_sec = 0.5
*    prediction_freq = 14
* Input Layer                    [50,40]         float      dequeue
*    shape = [50,40]
* Convolution 1D                 [25,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,40,16]
* Batch Normalization            [25,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [25,16]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [25,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Convolution 1D                 [25,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [25,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [25,32]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [12,32]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [12,64]         float      dequeue
*    filters = 64
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,64]
* Convolution 1D                 [12,64]         float      dequeue
*    filters = 64
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,64,64]
* Batch Normalization            [12,64]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[64]
*    beta = float[64]
*    mean = float[64]
*    variance = float[64]
* Activation                     [12,64]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [6,64]          float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Global average pooling 1D      [64]            float      dequeue
*    trainable = True
* Dense                          [3]             float      dequeue
*    units = 3
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[64,3]
*    bias = float[3]
* Activation                     [3]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[3].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[1].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 80.622 %
* (F1S) F1 Score 80.594 %
* 
* Name of class                                            (unlabelled)             Kyle             Sean
* (TP) True Positive or Correct Positive Prediction                  30              157              150
* (FN) False Negative or Incorrect Negative Prediction               12               42               27
* (FP) False Positive or Incorrect Positive Prediction               10               31               40
* (TN) True Negative or Correct Negative Prediction                 366              188              201
* (TPR) True Positive Rate or Sensitivity, Recall               71.43 %          78.89 %          84.75 %
* (TNR) True Negative Rate or Specificity, Selectivity          97.34 %          85.84 %          83.40 %
* (PPV) Positive Predictive Value or Precision                  75.00 %          83.51 %          78.95 %
* (NPV) Negative Predictive Value                               96.83 %          81.74 %          88.16 %
* (FNR) False Negative Rate or Miss Rate                        28.57 %          21.11 %          15.25 %
* (FPR) False Positive Rate or Fall-Out                          2.66 %          14.16 %          16.60 %
* (FDR) False Discovery Rate                                    25.00 %          16.49 %          21.05 %
* (FOR) False Omission Rate                                      3.17 %          18.26 %          11.84 %
* (F1S) F1 Score                                                73.17 %          81.14 %          81.74 %
*/


#define IMAI_TEST_AVG_ACC 0.80622009569378 // Accuracy
#define IMAI_TEST_AVG_F1S 0.8059351390387013 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 30, FN: 12, FP: 10, TN: 366, TPR: 0.7142857142857, TNR: 0.9734042553191, PPV: 0.75, NPV: 0.9682539682539, FNR: 0.2857142857142, FPR: 0.0265957446808, FDR: 0.25, FOR: 0.0317460317460, F1S: 0.7317073170731, }, \
 {name: "Kyle", TP: 157, FN: 42, FP: 31, TN: 188, TPR: 0.7889447236180, TNR: 0.8584474885844, PPV: 0.8351063829787, NPV: 0.8173913043478, FNR: 0.2110552763819, FPR: 0.1415525114155, FDR: 0.1648936170212, FOR: 0.1826086956521, F1S: 0.8113695090439, }, \
 {name: "Sean", TP: 150, FN: 27, FP: 40, TN: 201, TPR: 0.8474576271186, TNR: 0.8340248962655, PPV: 0.7894736842105, NPV: 0.8815789473684, FNR: 0.1525423728813, FPR: 0.1659751037344, FDR: 0.2105263157894, FOR: 0.1184210526315, F1S: 0.8174386920980, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 94.328 %
* (F1S) F1 Score 94.576 %
* 
* Name of class                                            (unlabelled)             Kyle             Sean
* (TP) True Positive or Correct Positive Prediction                 190              972              917
* (FN) False Negative or Incorrect Negative Prediction               22               77               26
* (FP) False Positive or Incorrect Positive Prediction               84                6               35
* (TN) True Negative or Correct Negative Prediction                1908             1149             1226
* (TPR) True Positive Rate or Sensitivity, Recall               89.62 %          92.66 %          97.24 %
* (TNR) True Negative Rate or Specificity, Selectivity          95.78 %          99.48 %          97.22 %
* (PPV) Positive Predictive Value or Precision                  69.34 %          99.39 %          96.32 %
* (NPV) Negative Predictive Value                               98.86 %          93.72 %          97.92 %
* (FNR) False Negative Rate or Miss Rate                        10.38 %           7.34 %           2.76 %
* (FPR) False Positive Rate or Fall-Out                          4.22 %           0.52 %           2.78 %
* (FDR) False Discovery Rate                                    30.66 %           0.61 %           3.68 %
* (FOR) False Omission Rate                                      1.14 %           6.28 %           2.08 %
* (F1S) F1 Score                                                78.19 %          95.91 %          96.78 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9432849364791288 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9457588682873624 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 190, FN: 22, FP: 84, TN: 1908, TPR: 0.8962264150943, TNR: 0.9578313253012, PPV: 0.6934306569343, NPV: 0.9886010362694, FNR: 0.1037735849056, FPR: 0.0421686746987, FDR: 0.3065693430656, FOR: 0.0113989637305, F1S: 0.7818930041152, }, \
 {name: "Kyle", TP: 972, FN: 77, FP: 6, TN: 1149, TPR: 0.9265967588179, TNR: 0.9948051948051, PPV: 0.9938650306748, NPV: 0.9371941272430, FNR: 0.0734032411820, FPR: 0.0051948051948, FDR: 0.0061349693251, FOR: 0.0628058727569, F1S: 0.9590527873704, }, \
 {name: "Sean", TP: 917, FN: 26, FP: 35, TN: 1226, TPR: 0.9724284199363, TNR: 0.9722442505947, PPV: 0.9632352941176, NPV: 0.9792332268370, FNR: 0.0275715800636, FPR: 0.0277557494052, FDR: 0.0367647058823, FOR: 0.0207667731629, F1S: 0.9678100263852, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 89.157 %
* (F1S) F1 Score 89.260 %
* 
* Name of class                                            (unlabelled)             Kyle             Sean
* (TP) True Positive or Correct Positive Prediction                  46              164              160
* (FN) False Negative or Incorrect Negative Prediction               10               26                9
* (FP) False Positive or Incorrect Positive Prediction               13                3               29
* (TN) True Negative or Correct Negative Prediction                 346              222              217
* (TPR) True Positive Rate or Sensitivity, Recall               82.14 %          86.32 %          94.67 %
* (TNR) True Negative Rate or Specificity, Selectivity          96.38 %          98.67 %          88.21 %
* (PPV) Positive Predictive Value or Precision                  77.97 %          98.20 %          84.66 %
* (NPV) Negative Predictive Value                               97.19 %          89.52 %          96.02 %
* (FNR) False Negative Rate or Miss Rate                        17.86 %          13.68 %           5.33 %
* (FPR) False Positive Rate or Fall-Out                          3.62 %           1.33 %          11.79 %
* (FDR) False Discovery Rate                                    22.03 %           1.80 %          15.34 %
* (FOR) False Omission Rate                                      2.81 %          10.48 %           3.98 %
* (F1S) F1 Score                                                80.00 %          91.88 %          89.39 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.891566265060241 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8925958526373462 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 46, FN: 10, FP: 13, TN: 346, TPR: 0.8214285714285, TNR: 0.9637883008356, PPV: 0.7796610169491, NPV: 0.9719101123595, FNR: 0.1785714285714, FPR: 0.0362116991643, FDR: 0.2203389830508, FOR: 0.0280898876404, F1S: 0.8, }, \
 {name: "Kyle", TP: 164, FN: 26, FP: 3, TN: 222, TPR: 0.8631578947368, TNR: 0.9866666666666, PPV: 0.9820359281437, NPV: 0.8951612903225, FNR: 0.1368421052631, FPR: 0.0133333333333, FDR: 0.0179640718562, FOR: 0.1048387096774, F1S: 0.9187675070028, }, \
 {name: "Sean", TP: 160, FN: 9, FP: 29, TN: 217, TPR: 0.9467455621301, TNR: 0.8821138211382, PPV: 0.8465608465608, NPV: 0.9601769911504, FNR: 0.0532544378698, FPR: 0.1178861788617, FDR: 0.1534391534391, FOR: 0.0398230088495, F1S: 0.8938547486033, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Kyle", "Sean"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xb9, 0x59, 0x80, 0x3c, 0x76, 0xae, 0x75, 0x43, 0xa8, 0xad, 0x3c, 0x74, 0x57, 0x97, 0xfe, 0xb4}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [1] (4 bytes)
#define IMAI_DATA_IN_COUNT (1)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [3] (12 bytes)
#define IMAI_DATA_OUT_COUNT (3)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (54)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
