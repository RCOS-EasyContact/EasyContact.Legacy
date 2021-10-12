# EasyContact/Backend/ContactSystem
Contact Book System Stores All Contact Informations
- [Representation](#representation)
- [Contributors](#contributors)

## Representation
- [Key.hpp](Key.hpp)
  - Minimum Element Stored in Database
  - Contains:
    - Contact Name **Key**
    - Contact Email Address **Attributes**
  - To Add More Addributes, Use This Class as a Super Class. Do Not Change the Representation of This Class.
- [Books.hpp](Books.hpp)
  - Database System for EasyContact
  - Contains:
    - A Set(`std::unordered_set`) of Unique `BCS::Key` Objects: Each Represent One Contact Information
    - A Map(`std::unordered_map`) of Unique Tag Set, Which Contains Contact Names
- [Book.cpp](Books.cpp)
  - Implementation for [Books.hpp](Books.hpp)

## Contributors
- Fall 2021
  - [reC4P7CH4](https://github.com/reC4P7CH4/)
  - [hayTambourineMan](https://github.com/hayTambourineMan/)
