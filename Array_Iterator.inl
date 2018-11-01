/* I pledge that I have neither given nor recieved any help on this assignment */

// Inline implementation of the Array_Iterator class

// Checks if the iterator is done
template <typename T>
bool Array_Iterator<T>::is_done(void)
{
  return this->currentIteration_ >= this->array_.cur_size_;
}

// Advances the iterator
template <typename T>
void Array_Iterator<T>::advance(void)
{
  this->currentIteration_++;
}

// Overload of '*' operator
template <typename T>
T & Array_Iterator<T>::operator * (void)
{
  return this->array_.data_[this->currentIteration_];
}

// Overload of '->' operator
template <typename T>
T * Array_Iterator<T>::operator -> (void)
{
  return &this->array_.data_[this->currentIteration_];
}
