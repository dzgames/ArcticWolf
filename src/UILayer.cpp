#include "../include/UILayer.hpp"

aw::UILayer::UILayer ()
: m_renderCache(generateRenderCache()) {}

const aw::UILayer::UIElementPriorityVector& aw::UILayer::getRenderVector () const {

    return m_renderCache;

}

void aw::UILayer::onNewElement (UIElement* element) {

    m_renderCache.push(element);

}

void aw::UILayer::onRenderCacheInvalidate () {

    m_renderCache.refresh();

}

aw::UILayer::UIElementPriorityVector aw::UILayer::generateRenderCache () const {

    UIElementPriorityVector cache;

    if (m_root != nullptr) {

        auto elements = m_root->getAll();

        for (unsigned int i = 0; i < elements.size(); ++i) {
            cache.push(elements[i]);
        }

    }

    return cache;

}
