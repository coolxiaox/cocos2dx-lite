#pragma once

#include "cocos2d.h"
#include "fmod.hpp"

class FmodPlayer : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(FmodPlayer);
    static FmodPlayer* getInstance();

    void playBackgroundMusic(const std::string& filename, bool loop = true);
    void stopBackgroundMusic();
    bool isBackgroundMusicPlaying();
    float getBackgroundMusicVolume();
    void setBackgroundMusicVolume(float volume);
    void pauseBackgroundMusic();
    void resumeBackgroundMusic();

    void playEffect(const std::string& filename, bool loop = false);
    void stopAllEffects();
    float getEffectsVolume();
    void setEffectsVolume(float volume);

private:
    FmodPlayer();
    ~FmodPlayer();
    void update(float delta);
    void memgc(float delta);

    static FmodPlayer  *_instance;
    FMOD::System       *_system;
    FMOD::Sound        *_backgroudSound;
    FMOD::Sound        *_effectSound;
    FMOD::Channel      *_backgroundChannel;
    FMOD::ChannelGroup *_mastergroup;
    void               *_extradriverdata;
    bool                _isBackgroundMusicPaused;
    bool                _isEffectPaused;
    float               _effectVolume;
    float               _backgroudVolume;
    FMOD_RESULT         _result;
    unsigned int        _version;
    std::map<FMOD::Sound*, FMOD::Channel*> _effect;
};
