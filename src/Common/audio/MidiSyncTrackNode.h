#ifndef MIDISYNCTRACKNODE_H
#define MIDISYNCTRACKNODE_H

#include "core/AudioNode.h"

namespace controller{
    class MainController;
}

namespace audio {

using controller::MainController;

class MidiSyncTrackNode : public audio::AudioNode
{

public:
    MidiSyncTrackNode(MainController *controller);

    ~MidiSyncTrackNode();
    void processReplacing(const SamplesBuffer &in, SamplesBuffer &out, int sampleRate, std::vector<midi::MidiMessage> &midiBuffer) override;
    void setPulseTiming(long pulsesPerInterval, double samplesPerPulse);
    void setIntervalPosition(long intervalPosition);
    void resetInterval();

    void start();
    void stop();

private:
    long pulsesPerInterval;
    double samplesPerPulse;
    long intervalPosition;
    int currentPulse;
    int lastPlayedPulse;
    bool running;
    bool hasSentStart;

    MainController *mainController;
};

} // namespace

#endif // MIDISYNCTRACKNODE_H
