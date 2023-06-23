#include "../real/coder.h"

#ifndef HELIX_STATIC_H
#define HELIX_STATIC_H

#ifdef __cplusplus
extern "C"
{
#endif

void clear_buf(void* buf, int nBytes);

#define HELIX_STATIC_DECLARE();        \
    static MP3DecInfo mp3DecInfo;      \
    static FrameHeader fh;             \
    static SideInfo si;                \
    static ScaleFactorInfo sfi;        \
    static HuffmanInfo hi;             \
    static DequantInfo di;             \
    static IMDCTInfo mi;               \
    static SubbandInfo sbi;

#define HELIX_STATIC_INIT(mp3DecInfo, fh, si, sfi, hi, di, mi, sbi) { \
    clear_buf(&mp3DecInfo, sizeof(MP3DecInfo));     \
                                                    \
    clear_buf(&fh,  sizeof(FrameHeader));           \
    clear_buf(&si,  sizeof(SideInfo));              \
    clear_buf(&sfi, sizeof(ScaleFactorInfo));       \
    clear_buf(&hi,  sizeof(HuffmanInfo));           \
    clear_buf(&di,  sizeof(DequantInfo));           \
    clear_buf(&mi,  sizeof(IMDCTInfo));             \
    clear_buf(&sbi, sizeof(SubbandInfo));           \
                                                    \
    mp3DecInfo.FrameHeaderPS =     (void *)&fh;     \
    mp3DecInfo.SideInfoPS =        (void *)&si;     \
    mp3DecInfo.ScaleFactorInfoPS = (void *)&sfi;    \
    mp3DecInfo.HuffmanInfoPS =     (void *)&hi;     \
    mp3DecInfo.DequantInfoPS =     (void *)&di;     \
    mp3DecInfo.IMDCTInfoPS =       (void *)&mi;     \
    mp3DecInfo.SubbandInfoPS =     (void *)&sbi;    \
};

#ifdef __cplusplus
}
#endif

#endif //HELIX_STATIC_H
