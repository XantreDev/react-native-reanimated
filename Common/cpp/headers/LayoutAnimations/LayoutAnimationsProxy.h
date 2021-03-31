//
//  LayoutAnimationObserver.hpp
//  DoubleConversion
//
//  Created by Szymon Kapala on 24/03/2021.
//

#ifndef LayoutAnimationsProxy_h
#define LayoutAnimationsProxy_h

#include <stdio.h>
#include <memory>
#include <functional>
#include <map>

namespace reanimated {

class MutableValue;

class LayoutAnimationsProxy {
  
public:
  LayoutAnimationsProxy(std::function<void(int, float)> _notifyAboutProgress, std::function<void(int)> _notifyAboutEnd);
  
  void startObserving(int tag, std::shared_ptr<MutableValue> sv);
  void stopObserving(int tag);
  
private:
  std::function<void(int, float)> notifyAboutProgress;
  std::function<void(int)> notifyAboutEnd;
  std::map<int, std::shared_ptr<MutableValue>> observedValues;
};

}

#endif /* LayoutAnimationsProxy_h */