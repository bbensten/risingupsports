<?php
/**
 * Implements hook_default_rules_configuration().
 */
function rus_helper_default_rules_configuration() {
  $configs = array();
  
  if (module_exists('commerce_product')) {
  $rule_data = '{ "rules_redirect_to_cart_after_adding_an_item" : {
    "LABEL" : "Redirect to Cart After Adding an Item",
    "PLUGIN" : "reaction rule",
    "REQUIRES" : [ "rules", "commerce_cart" ],
    "ON" : [ "commerce_cart_product_add" ],
    "DO" : [ { "redirect" : { "url" : "cart" } } ]
  }
}';
  $rule = rules_import($rule_data);
  $configs[$rule->name] = $rule;
  
  $rule_data = '{ "rules_copy_subscription_duration" : {
    "LABEL" : "Copy Subscription Duration",
    "PLUGIN" : "reaction rule",
    "REQUIRES" : [ "rules", "devel", "commerce_cart" ],
    "ON" : [ "commerce_cart_product_add" ],
    "IF" : [
      { "entity_has_field" : {
          "entity" : [ "commerce-product" ],
          "field" : "field_subscription_duration"
        }
      },
      { "data_is" : { "data" : [ "commerce-line-item:type" ], "value" : "product" } }
    ],
    "DO" : [
      { "data_set" : {
          "data" : [ "commerce-line-item:field-subscription-duration" ],
          "value" : [ "commerce-product:field-subscription-duration" ]
        }
      }
    ]
  }
}';
  $rule = rules_import($rule_data);
  $configs[$rule->name] = $rule;
  }
  return $configs;
}