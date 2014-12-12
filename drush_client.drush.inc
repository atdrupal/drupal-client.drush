<?php

/**
 * Implements hook_drush_command().
 */
function drush_client_drush_command() {
  $items = array();
  
  $items['dget'] = array(
    'description' => 'Perform GET request to Drupal site',
    'callback' => 'drush_client_drush_get',
    'arguments' => array(
      'path' => 'Request path',
    ),
  );
  
  $items['dpost'] = array(
    'description' => 'Perform POST request to Drupal site',
    'callback' => 'drush_client_drush_post',
    'arguments' => array(
      'path' => 'Request path',
      'data' => 'Input data in JSON format.',
      'button' => 'Button to click.',
    ),
  );

  return $items;
}

function drush_client_drush_get($url) {
  require_once dirname(__FILE__) . '/drush_client.php';
  $client = new DrushClient();
  return $client->get($url);
}

function drush_client_drush_post($url, $input, $button = NULL) {
  $keys = drush_get_option('keys');
  $vals = drush_get_option('values');
  
  require_once dirname(__FILE__) . '/drush_client.php';
  $client = new DrushClient();

  $params = json_decode($input, TRUE);
  return $client->post($url, $params ? $params : array(), $button);
}
