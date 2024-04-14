#include "Service2Reset.hpp"
#include "pluginlib/class_list_macros.hpp"

namespace rviz2_plugin_ser2res {
    Service2Reset::Service2Reset() {
        shortcut_key_ = 'r';
    }

    Service2Reset::~Service2Reset() {}

    void Service2Reset::onInitialize()
    {
        auto ros_node_abstraction = this->context_->getRosNodeAbstraction().lock();
        if (ros_node_abstraction) {
            auto node = ros_node_abstraction->get_raw_node();
            reset_time_srv_ = node->create_service<std_srvs::srv::Empty>(
                    ros_node_abstraction->get_node_name() + "/reset_time",
                    std::bind(&Service2Reset::resetService, this,
                              std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

        }
    }

    void Service2Reset::activate() {}

    void Service2Reset::resetService(const std::shared_ptr<rmw_request_id_t>,
                                           const std::shared_ptr<std_srvs::srv::Empty::Request>,
                                           const std::shared_ptr<std_srvs::srv::Empty::Response>)
    {
        this->context_->getRootDisplayGroup()->reset();
    }

    void Service2Reset::deactivate() {}

}

PLUGINLIB_EXPORT_CLASS(rviz2_plugin_ser2res::Service2Reset, rviz_common::Tool)
