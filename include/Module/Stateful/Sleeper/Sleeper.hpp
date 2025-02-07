/*!
 * \file
 * \brief Class module::Sleeper.
 */
#ifndef SLEEPER_HPP_
#define SLEEPER_HPP_

#include <cstdint>

#include "Module/Stateful/Stateful.hpp"

namespace spu
{
namespace module
{
namespace slp
{
enum class tsk : size_t
{
    sleep,
    SIZE
};

namespace sck
{
enum class sleep : size_t
{
    status
};
}
}

class Sleeper : public Stateful
{
  public:
    inline runtime::Task& operator[](const slp::tsk t);
    inline runtime::Socket& operator[](const slp::sck::sleep s);
    inline runtime::Socket& operator[](const std::string& tsk_sck);

  protected:
    size_t ns;

  public:
    Sleeper(const size_t ns = 0);
    virtual ~Sleeper() = default;
    virtual Sleeper* clone() const;

    size_t get_ns() const;
    void set_ns(const size_t ns);

    void sleep(const int frame_id = -1, const bool managed_memory = true);

  protected:
    virtual void _sleep(const size_t frame_id);
};
}
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include "Module/Stateful/Sleeper/Sleeper.hxx"
#endif

#endif /* SLEEPER_HPP_ */
