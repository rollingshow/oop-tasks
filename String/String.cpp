#include <iostream>
#include "String.h"

String String::left(int range)
{
  if (range > len || range < 0)
  {
    std::cerr << 'Wrong range in String::left()';
    return NULL;
  }

  // создаем массив
  char *new_array = new char[range + 1];

  // заполняем массив
  for (int i = 0; i < range; i++)
  {
    new_array[i] = array[i];
  }
  new_array[range] = '\0';

  // создаём объект и возвращаем
  String result = new_array;

  return result;
}

String String::right(int range)
{
  if (range > len || range < 0)
  {
    std::cerr << 'Wrong range in String::right()';
    return NULL;
  }

  // создаем массив
  char *new_array = new char[range + 1];

  // заполняем массив
  for (int i = len - range; i < len; i++)
  {
    new_array[i - len + range] = array[i];
  }
  new_array[range] = '\0';

  // создаём объект и возвращаем
  String result = new_array;

  return result;
}

String String::mid(int start)
{
  if (start >= len || start < 0)
  {
    std::cerr << 'Wrong range in String::mid()';
    return NULL;
  }

  // создаем массив
  char *new_array = new char[len - start + 1];

  // заполняем массив
  for (int i = start; i < len; i++)
  {
    new_array[i - start] = array[i];
  }
  new_array[len - start] = '\0';

  // создаём объект и возвращаем
  String result = new_array;

  return result;
}

String String::mid(int start, int range)
{
  if (start >= len || start < 0 || range + start - 1 >= len || range < 0)
  {
    std::cerr << 'Wrong range in String::mid()';
    return NULL;
  }

  // создаем массив
  char *new_array = new char[range + 1];

  // заполняем массив
  for (int i = start; i < start + range; i++)
  {
    new_array[i - start] = array[i];
  }
  new_array[range] = '\0';

  // создаём объект и возвращаем
  String result = new_array;

  return result;
}

String String::concat(String input)
{
  // находим длину второй строки и создаем массив
  int len2 = get_len(input.to_char());
  char *new_array = new char[len + len2 + 1];

  // заполняем массив
  for (int i = 0; i < len; i++)
  {
    new_array[i] = array[i];
  }
  for (int i = 0; i < len2; i++)
  {
    new_array[i + len] = input.to_char()[i];
  }

  // освобождаем старую память
  free(array);

  // записываем новую длину и меняем указатель
  len = len + len2;
  array = new_array;

  return *(this);
}

String::String()
{
  len = 0;
  array = new char[len + 1];

  eol();
}

String::String(const char *input)
{
  len = get_len(input);
  array = new char[len + 1];

  for (int i = 0; i < len; i++)
  {
    array[i] = input[i];
  }

  eol();
}

int String::length()
{
  return len;
}

char *String::to_char()
{
  return array;
}

void String::eol()
{
  array[len] = '\0';
}

int String::get_len(const char *input)
{
  int i = 0;
  while (input[i] != '\0')
  {
    i++;
  }

  return i;
}
