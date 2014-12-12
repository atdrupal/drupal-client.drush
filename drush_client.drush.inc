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
    'options' => array(
      'uid' => 'User ID to auth, 0 to disable',
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
    'options' => array(
      'uid' => 'User ID to auth, 0 to disable',
    ),
  );

  return $items;
}

function drush_client_drush_get($url) {
  require_once dirname(__FILE__) . '/drush_client.php';
  $uid = drush_get_option('uid');
  $client = new DrushClient($uid);
  return $client->get($url);
}

function drush_client_drush_post($url, $input, $button = NULL) {  
  require_once dirname(__FILE__) . '/drush_client.php';
  $uid = drush_get_option('uid');
  $client = new DrushClient($uid);

  $params = json_decode($input, TRUE);
  return $client->post($url, $params ? $params : array(), $button);
}
