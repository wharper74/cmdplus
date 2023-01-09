#pragma once
#include <string>

namespace cmdplus {
  /** \brief
   *  An element of the command line of type T
   */
  template<typename T> class Element {
    public:
      using id_type = int;
      using value_type = T;

      Element(const Element::id_type& id, const std::string& name, const std::string& description, bool optional = true ) : _id(id), _name(name), _value(T()), _description(description), _optional(optional) {}
      Element(const Element&) = delete;
      Element(Element&& source) : _id(source._id), _name(source._name), _value(std::move(source._value)), _description(source._description), _optional(source._optional) {}
      ~Element() = default;

      Element& operator=(const Element&) = delete;
      Element& operator=(Element&& source) {
        if( &source != this ) {
          _id = std::move(source._id);
          _name = std::move(source._name);
          _value = std::move(source._value);
          _description = std::move(source._description);
          _optional = std::move(source._optional);
        }
      }

      bool& operator==(const Element& other) {
        return (this == &other || this->getName() == other.getName() );
      }
      bool& operator!=(const Element& other) {
        return ! ((*this) == other);
      }

      const std::string& getName() const noexcept { return _name;}
      const Element::value_type& getValue() const noexcept {return _value;}
      const std::string& getDescription() const noexcept {return _description;}

      const bool isOptional() const noexcept {return _optional;}
      const bool isMandatory() const noexcept {return _optional == false;}

    private:
      Element::id_type _id; /// element identifier
      std::string _name; /// element name
      Element::value_type _value; /// element value
      std::string _description; /// full description of the element
      bool _optional; /// <b>true</b> if the element is optional
  };
}
