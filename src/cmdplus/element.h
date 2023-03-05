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

      Element(const Element::id_type& id, const std::string& short_name, const std::string& full_name, const std::string& description, bool optional = true ) : _id(id), _short_name(short_name), _full_name(full_name), _value(T()), _description(description), _optional(optional) {}
      Element(const Element&) = delete;
      Element(Element&& source) = delete;
      ~Element() = default;

      const Element::id_type getId() const noexcept { return _id; }
      const std::string& getShortName() const noexcept { return _short_name;}
      const std::string& getFullName() const noexcept { return _full_name; }
      const Element::value_type& getValue() const noexcept {return _value;}
      const std::string& getDescription() const noexcept {return _description;}

      const bool isOptional() const noexcept {return _optional;}
      const bool isMandatory() const noexcept {return _optional == false;}

    private:
      Element::id_type _id; /// element identifier
      bool _optional; /// <b>true</b> if the element is optional

      std::string _short_name; /// the element name when prefixed with a single "-"
      std::string _full_name; // the element name when prefixed with a double "-"
      
      Element::value_type _value; /// element value
      

      std::string _description; /// full description of the element
      
  };
}
