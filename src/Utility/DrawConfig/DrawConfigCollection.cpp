#include <DDE/Utility/DrawConfig/DrawConfigCollection.hpp>

// TODO: Documentation
DDE::DrawConfigCollection::DrawConfigCollectionIterator
DDE::DrawConfigCollection::begin() {
  return this->_configs.begin();
}

// TODO: Documentation
DDE::DrawConfigCollection::DrawConfigCollectionIterator
DDE::DrawConfigCollection::end() {
  return this->_configs.end();
}

// TODO: Documentation
DDE::DrawConfigCollection::ConstDrawConfigCollectionIterator
DDE::DrawConfigCollection::begin() const {
  return this->_configs.cbegin();
}

// TODO: Documentation
DDE::DrawConfigCollection::ConstDrawConfigCollectionIterator
DDE::DrawConfigCollection::end() const {
  return this->_configs.cend();
}
