#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

namespace sdds {
   template<typename T>
   class Collection {
      std::string m_name;
      T* m_collection;
      size_t m_size;
      T* m_dummy;
      void (*m_observer)(const Collection<T>&, const T&) {};
   public:
      Collection(const std::string& name) : m_name(name) {
         m_collection = nullptr;
         m_size = 0;
         m_dummy = nullptr;
      }

      const std::string& name() const {
         return m_name;
      }

      size_t size() const {
         return m_size;
      }

      void setObserver(void (*observer)(const Collection<T>&, const T&)) {
         m_observer = observer;
      }

      Collection<T>& operator+=(const T& item) {
         bool found{};
         T* tmp{};

         for (size_t i = 0; i < m_size && !found; i++) {
            found = m_collection[i].title() == item.title();
         }

         if (!found) {
            tmp = new T[++m_size];
            if (m_size > 1) {
               for (size_t i = 0; i < m_size - 1; i++) {
                  tmp[i] = m_collection[i];
               }
            }            
            tmp[m_size - 1] = item;
            delete[] m_collection; // might cause mem leak ??
            m_collection = tmp;

            if (m_observer) m_observer(*this, item);
         }
         return *this;
      }

      T& operator[](size_t idx) const {
         if (!(idx >= 0 && idx < m_size)) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection jas [" + std::to_string(m_size) + "] items.");
         }
         return m_collection[idx];
      }

      T* operator[](const std::string& title) const {
         bool found{};
         T* item{};
         size_t i{};
         for (; i < m_size && !found; i++) {
            found = m_collection[i].title() == title;
         }

         if (found) {
            item = &m_collection[i - 1];
         }
         else {
            item = nullptr;
         }

         return item;
      }

      std::ostream& display(std::ostream& ostr) const {
         for (size_t i = 0; i < m_size; i++) {
            ostr << m_collection[i];
         }
         return ostr;
      }

      ~Collection() {
         delete[] m_collection;
      }
   };

   template<typename T>
   std::ostream& operator<<(std::ostream& ostr, const Collection<T>& C) {
      return C.display(ostr);
   }
}



#endif // !SDDS_COLLECTION_H

