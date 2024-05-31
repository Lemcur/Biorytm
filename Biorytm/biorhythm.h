#pragma once

#define BIORYTM_FIZYCZNY 23
#define BIORYTM_EMOCJONALNY 28
#define BIORYTM_INTELEKTUALNY 33

typedef struct {
    int cycle_length;
    float current_value;
    int is_growing; // 1 - rosnie, 0 - spada
} Biorhythm;
