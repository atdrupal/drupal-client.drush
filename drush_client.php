<?php

/**
 * Class helps perform request to Drupal site.
 *
 * Example usage:
 *  (new DrushClient())->post(
 *     'admin/config/system/site-information', 
 *     array("site_name" => "Drush client"),
 *     "Save configuration"
 *   );
 *
 */
class DrushClient extends DrupalWebTestCase {
  private $uid;

  public function __construct($uid = 1) {
    $this->uid = $uid;
  }

  private function auth() {
    global $user;

    if ($this->uid) {
      if (!$user || empty($user->uid)) {
        $user = user_load($this->uid);
        $url = user_pass_reset_url($user);
        $this->drupalGet($url);
        $this->drupalPost(NULL, array(), "Log in");
      }
    }
  }

  public function get($path, array $options = array(), array $headers = array()) {
    $this->auth();
    return $this->drupalGet($path, $options, $header);
  }

  public function post($path, $edit, $submit, array $options = array(), array $headers = array(), $form_html_id = NULL, $extra_post = NULL) {
    $this->auth();
    return $this->drupalPost($path, $edit, $submit, $options, $header, $form_html_id, $extra_post);
  }
  
  // Disable db query
  protected function assert($status, $message = '', $group = 'Other', array $caller = NULL) {}
  protected function verbose($message) {}
  protected function error($message = '', $group = 'Other', array $caller = NULL) {}
}
