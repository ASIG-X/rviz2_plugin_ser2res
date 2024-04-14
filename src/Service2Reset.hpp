#ifndef Service2Reset_HPP_
#define Service2Reset_HPP_

#include <rclcpp/service.hpp>
#include <std_srvs/srv/empty.hpp>

#include "rviz_common/tool.hpp"
#include "rviz_common/display_group.hpp"
#include "rviz_common/visualization_manager.hpp"

namespace rviz2_plugin_ser2res {

    class Service2Reset : public rviz_common::Tool
    {
      Q_OBJECT

      public:
        Service2Reset();
        ~Service2Reset();

        virtual void onInitialize();
        virtual void activate();
        virtual void deactivate();

      private:
        void resetService(const std::shared_ptr<rmw_request_id_t>,
                          const std::shared_ptr<std_srvs::srv::Empty::Request>,
                          const std::shared_ptr<std_srvs::srv::Empty::Response>);

        rclcpp::Service<std_srvs::srv::Empty>::SharedPtr reset_time_srv_;
    };

}

#endif
